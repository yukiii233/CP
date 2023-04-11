#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    string s;
    getline(cin, s);
    bool f = 0;
    int cnt = 0;
    string t;
    for (auto x : s) {
        if (x == '6') cnt++;
        else {
            if (cnt > 9) t += "27";
            else if (cnt > 3) t += "9";
            else for (int i = 1; i <= cnt; i++) t += "6";
            t += x;
            cnt = 0;
        }
    }
    if (cnt > 9) t += "27";
    else if (cnt > 3) t += "9";
    else for (int i = 1; i <= cnt; i++) t += "6";
    cout << t;
    cout << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}