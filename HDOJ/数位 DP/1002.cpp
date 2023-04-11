#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int pow10[N], f[N][13][3][2];
int dig[N], cnt;

int dfs(int p, int r, int cur, int limit) {
    int &res = f[p][r][cur][limit];
    if (res != -1) return res;
    if (p == 0) return r == 0 && cur == 2;
    res = 0;
    int mx = limit ? dig[p] : 9;
    for (int i = 0; i <= mx; i++) {
        int nxt = cur;
        if (cur == 0 && i == 1) nxt = 1;
        else if (cur == 1 && i == 3) nxt = 2;
        else if (cur == 1 && i != 3 && i != 1) nxt = 0;
        int nr = (r + i * pow10[p - 1]) % 13;
        res += dfs(p - 1, nr, nxt, limit && i == mx);
    }
    return res;
}

int solve(int n) {
    cnt = 0;
    memset(f, -1, sizeof f);
    while (n) {
        dig[++cnt] = n % 10;
        n /= 10;
    }
    return dfs(cnt, 0, 0, 1);
}

int main() {
    pow10[0] = 1;
    for (int i = 1; i <= 9; i++) pow10[i] = pow10[i - 1] * 10;
    int n;
    while (scanf("%d", &n) == 1) {
        printf("%d\n", solve(n));
    }
    return 0;
}