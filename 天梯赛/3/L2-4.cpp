#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e3 + 5;

int n, m;
int p[N];
int stk[N], top;

bool solve() {
    top = 0;
    for (int i = 1; i <= n; i++) cin >> p[i];
    int it = 1;
    for (int i = 1; i <= n; i++) {
        if (it > n && stk[top] != i) return 0;
        //printf("%d %d %d\n", i, top, it);
        if (top && stk[top] == i) {
            top--;
        } else {
            while (it <= n && p[it] != i) {
                stk[++top] = p[it++];
                if (top > m) return 0;
            }
            if (it <= n && p[it] == i) ++it;
            else return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> n >> m >> T;
    while (T--) {
        solve() ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}