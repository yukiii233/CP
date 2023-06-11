#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 3e5 + 5;

int n, a[N], b[N];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
    }
    if (n & 1) return puts("YES"), void();
    for (int i = 2; i <= n; i++) {
    	b[i] = a[i] - a[i - 1];
    }
    ll sum = 0;
    for (int i = 2; i <= n; i += 2) {
    	sum += b[i];
    }
    sum >= 0 ? puts("YES") : puts("NO");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}