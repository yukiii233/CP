#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 47777 + 5;

int tp, k;
int d[60005], P[60005], num[60005], pcnt;
bool vis[60005];
ll res;

void dfs(int p, int lst, int rem, ll x) {
    if (x > (1ll << 62)) return;
    if (lst == 0 && rem != 1) return;
    if (rem == 1) {
        res = min(res, x);
        return;
    }
    ll s1 = 1;
    for (int i = 0; i <= lst; i++) {
        if (rem % (i + 1) == 0) dfs(p + 1, i, rem / (i + 1), x * s1);
        s1 *= P[p];
        if ((1ll << 62) / s1 < x) break;
    }
}
void init() {
    for (int i = 2; i <= 60000; i++) {
        if (!vis[i]) {
            P[++pcnt] = i;
            d[i] = 2;
            num[i] = 1;
        }
        for (int j = 1; j <= pcnt && i * P[j] <= 60000; j++) {
            vis[i * P[j]] = 1;
            if (i % P[j]) {
                d[i * P[j]] = d[i] * 2;
                num[i * P[j]] = 1;
            } else {
                d[i * P[j]] = d[i] / (num[i] + 1) * (num[i] + 2);
                num[i * P[j]] = num[i] + 1;
                break;
            }
        }
    }
}
void solve0() {
    res = (1ll << 62) + 1;
    dfs(1, 62, k, 1);
    if (res <= (1ll << 62)) printf("%lld\n", res);
    else printf("INF\n");
}
void solve1() {
    for (int i = k; i <= 60000; i++) {
        if (k + d[i] == i) return printf("%d\n", i), void();    
    }
    puts("Illegal");
}

int main() {
    int T, Case = 0;
    d[1] = 1;
    init();
    scanf("%d", &T);
    while (T--) {
        printf("Case %d: ", ++Case);
        scanf("%d %d", &tp, &k);
        if (tp == 0) solve0();
        else solve1();
    }
    return 0;
}