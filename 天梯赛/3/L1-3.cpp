#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

string a = "ong,", b = "ong.";
string s;

void solve() {
    getline(cin, s);
    //cout << s << endl;
    //return;
    int n = s.size();
    bool ha = 0, hb = 0;
    for (int i = 0; i < n; i++) {
        //cout << s.substr(i, 4) << '\n';
        if (s.substr(i, 4) == a) ha = 1;
        if (s.substr(i, 4) == b) hb = 1;
    }
    if (ha && hb) {
        string t;
        int pos;
        for (int i = 0; i < n; i++) {
            if (s.substr(i, 4) == a) {
                int cnt = 0;
                pos = i + 5;
                for (int k = 0; k < pos; k++) t += s[k];
            }
            if (s.substr(i, 4) == b) {
                int cnt = 0, j;
                for (j = i; j >= 0; j--) {
                    if (s[j] == ' ') cnt++;
                    if (cnt == 3) break;
                }
                for (int k = pos; k < j; k++) t += s[k];
                if (j == pos - 1) t += "qiao ben zhong.";
                else t += " qiao ben zhong.";;
            }
        }
        cout << t;
    } else cout << "Skipped";
}

int main() {
    int T;
    cin >> T;
    getline(cin, s);
    while (T--) {
        solve();
        if (T) cout << '\n';
    }
    return 0;
}