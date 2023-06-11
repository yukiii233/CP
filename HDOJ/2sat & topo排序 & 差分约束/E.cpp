#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
const int N = 168;

int head[N], ecnt;
struct Edge {
    int nxt, v, w;
} e[N << 2];
void add_edge(int u, int v, int w) {
    e[++ecnt] = (Edge){head[u], v, w}, head[u] = ecnt;
}

/*
详细解释一下。
为避免负数，时间计数1～24。令：
R[i] i时间需要的人数 （1<=i<=24）
T[i] i时间应聘的人数 （1<=i<=24）
x[i] i时间录用的人数 （0<=i<=24），其中令x[0]=0
再设s[i]=x[0]+x[1]+……+x[i] （0<=i<=24），
由题意，可得如下方程组：
(1) s[i]-s[i-8]>=R[i]        (8<=i<=24)
(2) s[i]-s[16+i]>=R[i]-s[24] (1<=i<=7)
(3) s[i]-s[i-1]>=0           (1<=i<=24)
(4) s[i-1]-s[i]>=-T[i]       (1<=i<=24)

这个差分约束有个特殊的地方，(2)的右边有未知数s[24]。
这时可以通过枚举s[24]=ans来判断是否有可行解。
即(2)变形为(2') s[i]-s[16+i]>=R[i]-ans (1<=i<=7)
再通过SPFA求解(1)(2')(3)(4)。

不过最后有可能出现这种情况：
(1)(2')(3)(4)虽然有解，但求出的s[24]小于代入(2')里的ans！
这时，显然得到的s[]不满足原来的(2)了（请仔细比较(2)与(2')）。
不过虽然得到的解不满足原方程组，但这并不代表(1)(2)(3)(4)在s[24]=ans时没有可行解！
此外，值得注意的是，当得到的s[24]>ans时，虽然s[24]不一定是最优解，但把ans置成s[24]后，确实是可行解。

所以，简单把(2)置换成(2')是有问题的！
为了等价原命题，必须再加上条件：s[24]>=ans
这就是所谓加出来的那条边（5） s[24]－s[0]>=ans

最后说一下，SPFA后判dis[24]==ans其实是没有必要的。
*/
int n, R[25];
int dis[N], qcnt[N], b[N];
bool inq[N];
bool BellmanFord(int start) {
    queue<int> q;
    memset(dis, -0x3f, sizeof dis);
    memset(qcnt, 0, sizeof qcnt);
    memset(inq, 0, sizeof inq);
    q.push(start);
    dis[start] = 0;
    inq[start] = 1;
    qcnt[start]++;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v, w = e[i].w;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = 1;
                    qcnt[v]++;
                    if (qcnt[v] > n) return 0;
                }
            }
        }
    }
    return 1;
}

void rmain() {
    /*i - 7, i
    i + (n - (8 - i) + 1)
    n - 7 + i (i < 8)*/
    memset(b, 0, sizeof b);
    for (int i = 1; i <= 24; i++) scanf("%d", &R[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        x++;
        b[x]++;
    }
    for (int re = 0; re <= n ; re++) {
        memset(head, 0, sizeof head);
        ecnt = 0;
        for (int i = 1; i <= 24; i++) {
            if (i < 8) {
                int l = 24 - 7 + i;
                add_edge(l - 1, i, R[i] - re);
            } else {
                add_edge(i - 8, i, R[i]);
            }
            add_edge(i, i - 1, -b[i]);
            add_edge(i - 1, i, 0);
        }
        add_edge(24, 0, -re);
        bool flag = BellmanFord(0) && (re == dis[24]);
        //printf("%d %d %d\n", re, flag, dis[24]);
        if (flag) {
            printf("%d\n", re);
            return;
        }
    }
    puts("No Solution");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        rmain();
    }
    return 0;
}