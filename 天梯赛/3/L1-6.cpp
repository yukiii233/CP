#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 3; i < 6; i++) b += s[i];
    for (int i = 0; i < 3; i++) a += s[i];
    a == b ? cout << "You are lucky!\n" : cout << "Wish you good luck.\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}