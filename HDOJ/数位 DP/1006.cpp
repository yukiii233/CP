#include <bits/stdc++.h>
using namespace std;

const int N = 11;
int pow2[N];
int a, b, re;
int dig[N], cnt;
int f[N][4601];

int dfs(int p, int sum, int limit) {
    if (sum < 0) return 0;
    if (p == 0) return sum >= 0;
    if (!limit && f[p][sum] != -1) return f[p][sum];
    int res = 0;
    int mx = limit ? dig[p] : 9;
    for (int i = 0; i <= mx; i++) {
        res += dfs(p - 1, sum - pow2[p - 1] * i, limit && i == mx);
    } 
    if (!limit) f[p][sum] = res;
    return res;
}

void solve() {
    static int Case = 0;
    ++Case;
    scanf("%d %d", &a, &b);
    re = 0;
    int p = 0;
    while (a) {
        int cur = a % 10;
        re += cur * pow2[p++];
        a /= 10;
    }
    cnt = 0;
    while (b) {
        dig[++cnt] = b % 10;
        b /= 10;
    }
    printf("Case #%d: %d\n", Case, dfs(cnt, re, 1));
}

int main() {
    int T;
    pow2[0] = 1;
    for (int i = 1; i < N; i++) pow2[i] = pow2[i - 1] * 2;
    memset(f, -1, sizeof f);
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}