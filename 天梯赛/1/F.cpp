#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 5;

string s, t;
char a[N], b[N];

void solve() {
    scanf("%s %s", a + 1, b + 1);
    int n = strlen(a + 1), m = strlen(b + 1);    
    for (int i = 2; i <= n; i++) {
        if (a[i] % 2 == a[i - 1] % 2) s += max(a[i], a[i - 1]);
    }
    for (int i = 2; i <= m; i++) {
        if (b[i] % 2 == b[i - 1] % 2) t += max(b[i], b[i - 1]);
    }
    if (s == t) cout << s << endl;
    else cout << s << endl << t << endl;
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}