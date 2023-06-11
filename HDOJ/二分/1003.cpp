#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

ll m;
int n, k, a[N], s[N];

bool check(int mid) {
    ll res = 0;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + (a[i] >= mid);
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(s + k - 1, s + n + 1, s[i - 1] + k) - s;
        res += n - pos + 1;
    }
    return res >= m;
}

void solve() {
    scanf("%d %d %lld", &n, &k, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int l = 1, r = *max_element(a + 1, a + n + 1), ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}