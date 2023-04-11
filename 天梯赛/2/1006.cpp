#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

string s;
string t[3] = {"chi1", "huo3", "guo1"};

bool pd(char x) {
    if (x >= '0' && x <= '9') return 0;
    if (x >= 'a' && x <= 'z') return 0;
    if (x >= 'A' && x <= 'Z') return 0;
    return 1;
}
bool check(string s) {
    int now = 0;
    for (int i = 0; i < (int)(s.size()); i++) {
        if (i + 4 > (int)(s.size()) || now == 2) break;
        if ((i == 0 || (i != 0 && s[i - 1] == ' ')) && s.substr(i, 4) == t[now] && (i + 4 == (int)(s.size()) || pd(s[i + 4]))) {
            now++;
        }
    }
    return now == 2;
}

void solve() {
    int cnt = 0, res = 0, fi = 0;
    while (getline(cin, s)) {
        if (s == ".") break;
        cnt++;
            if (check( s)) {
                if (res == 0) res++, fi = cnt; 
                else res++;
            }
    }
    cout << cnt << '\n';
    if (res == 0) cout << "-_-#\n";
    else cout << fi << ' ' << res << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}