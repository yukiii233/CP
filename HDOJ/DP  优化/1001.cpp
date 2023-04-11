#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, L, R, a[N];
int q1[N], q1l, q1r, q2[N], q2l, q2r;

void solve() {
    q1l = q2l = 0, q2r = q1r = -1;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int j = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        while (q1l <= q1r && a[q1[q1r]] <= a[i]) q1r--;
        while (q2l <= q2r && a[q2[q2r]] >= a[i]) q2r--;
        q1[++q1r] = i, q2[++q2r] = i; 
        while (a[q1[q1l]] - a[q2[q2l]] > R) {
            j++;
            while (q1l <= q1r && j > q1[q1l]) q1l++;
            while (q2l <= q2r && j > q2[q2l]) q2l++;
        }
        if (a[q1[q1l]] - a[q2[q2l]] >= L) ans = max(ans, i - j + 1);
    }
    printf("%d\n", ans);
}

int main() {
    while (scanf("%d %d %d", &n, &L, &R) == 3) {
        solve();
    }
    return 0;
}