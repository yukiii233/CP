//https://blog.csdn.net/tyxacm/article/details/97156620?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-7.edu_weight&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-7.edu_weight
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m;
int a[N * 2][33], b[N * 2][33];

void insert(int x, int n) {
    for (int i = 30; i >= 0; i--) {
        a[n][i] = a[n - 1][i];
        b[n][i] = b[n - 1][i];
    }
    int tim = n;
    for (int i = 30; i >= 0; i--) {
        if ((x >> i) & 1) {
            if (!a[n][i]) {
                a[n][i] = x;
                b[n][i] = tim;
                break;
            }
            if (b[n][i] < tim) {
                swap(a[n][i], x);
                swap(b[n][i], tim);
            }
            x ^= a[n][i];
        }
    }
}
int query(int l, int r) {
    int res = 0;
    for (int i = 30; i >= 0; i--) if (b[r][i] >= l) {
        res = max(res, res ^ a[r][i]);
    }
    return res;
}

void solve() {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    scanf("%d %d", &n, &m);
    int cnt = n;
    int res = 0, l, r, x, op;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        insert(x, i);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &op);
        if (op == 0) {
            scanf("%d %d", &l, &r);
            l = (l ^ res) % cnt + 1;
            r = (r ^ res) % cnt + 1;
            if (l > r) swap(l, r);
            res = query(l, r);
            printf("%d\n", res);
        } else {
            scanf("%d", &x);
            x ^= res;
            insert(x, ++cnt);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}