#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1000 + 5;

string s, t;
bool del[N];
bool doa(char x) {
    if (x >= '0' && x <= '9') return 1;
    if (x >= 'a' && x <= 'z')  return 1;
    if (x >= 'A' && x <= 'Z')  return 1;
    return 0;
}
bool check(int i) {
    return i < 0 || i >= (int)(t.size()) || !doa(t[i]);
}

void solve() {
    getline(cin , s);
    cout << s << '\n';
    cout << "AI: ";
    memset(del, 0, sizeof del);
    int n = s.size();
    t.clear();
    int i;
    for (i = 0; i < n; i++) {
        if (s[i] == ' ') del[i] = 1;
        else break;
    }
    for (; i < n; i++) {
        if (s[i] == ' ') {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == ' ') del[j] = 1;
                else break;
            }
        }
    }
    for (i = n - 1; i >= 0; i--) {
        if (s[i] == ' ') del[i] = 1;
        else break;
    }
    for (i = 0; i < n; i++) {
        if (s[i] != ' ' && !doa(s[i]) && i != 0 && s[i - 1] == ' ') 
            del[i - 1] = 1;
    }
    for (int i = 0; i < n; i++) if (!del[i]) t += s[i];
    n = t.size();
    for (int i = 0; i < n; i++) {
        if (t[i] >= 'A' && t[i] <= 'Z' && t[i] != 'I') t[i] = t[i] - 'A' + 'a';
    }
    string tt;
    i = 0;
    for (i = 0; i < n; i++) {
        if (t.substr(i, 7) == "can you" && check(i - 1) && check(i + 7)) {
            tt += "I can";
            i += 6;
        } else if (t.substr(i, 9) == "could you" && check(i - 1) && check(i + 9)) {
            tt += "I could";
            i += 8;
        } else if (t.substr(i, 1) == "I" && check(i - 1) && check(i + 1)) {
            tt += "you";
            i += 0;
        } else if (t.substr(i, 2) == "me" && check(i - 1) && check(i + 2)) {
            tt += "you";
            i += 1;
        } else if (t[i] == '?') tt += "!";
        else tt += t[i];
    }
    
    cout << tt << '\n';
}

int main() {
    int T;
    cin >> T;
    getline(cin, s);
    while (T--) {
        solve();
    }
    return 0;
}