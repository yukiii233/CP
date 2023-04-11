#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

string s;

void solve() {
    cin >> s;
    int x = (s[0] - '0') * 10 + s[1] - '0';
    if ((int)(s.size()) != 6) {
    if (x < 22) {
        s.insert(s.begin(), '0');
        s.insert(s.begin(), '2');
    } else {
        s.insert(s.begin(), '9');
        s.insert(s.begin(), '1');
        }
    }
    s.insert(s.begin() + 4, '-');
    cout << s << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}