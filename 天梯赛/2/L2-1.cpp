#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e3 + 5;

char s2[N];
int s1[N], t1, t2;

void solve() {
    int n, x;
    char s[7];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        s1[++t1] = x;
    }
    for (int i = 1; i < n; i++) {
        scanf("%s", s);
        s2[++t2] = s[0];
    }
    while (t2) {
        int x = s1[t1--], y = s1[t1--];
        char op = s2[t2--];
        if (op == '/' && x == 0) return printf("ERROR: %d/%d\n", y, x), void();
        if (op == '+') s1[++t1] = x + y;
        else if (op == '-') s1[++t1] = y - x;
        else if (op == '*') s1[++t1] = x * y;
        else if (op == '/') s1[++t1] = y /x;
    }
    printf("%d\n", s1[1]);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}