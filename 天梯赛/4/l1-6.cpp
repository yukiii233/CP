#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

string e = "easy", q = "qiandao";
string s;

int n, m;

void solve() {
    cin >> n >> m;
    getline(cin, s);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        bool f = 1;
        for (int i = 0; i < (int)(s.size()); i++) {
            if (s.substr(i, 4) == e || s.substr(i, 7) == q) {
                f = 0;
                break;
            }
        }
        if (f == 0) continue;
        cnt++;
        if (cnt == m + 1) {
            cout << s << '\n';
            return;
        }
    }
    cout << "Wo AK le" << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}