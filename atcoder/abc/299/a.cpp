#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    string s;
    int n, x;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '*') x = i;
    }
    bool p = 0, q = 0;
    for (int i = 0; i < x; i++) if (s[i] == '|') p = 1;
    for (int i = x + 1; i < n; i++) if (s[i] == '|') q = 1;
    if (p && q) cout << "in\n";
	else cout << "out\n";
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}