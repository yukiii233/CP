#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    string s;
    int n;
    cin >> n >> s;
    bool gg = 0, xx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') gg = 1;
        if (s[i] == 'x') xx = 1;
    }
    bool out = 1;
    if (xx || !gg) out = 0;
    out ? cout << "Yes\n" : cout << "No\n";
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
} 
