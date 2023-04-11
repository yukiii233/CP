#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

set<int> s[7];

void solve() {
    int n;
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++) s[i].insert(-j);
    for (int i = 1; i <= 6; i++) {
        int x;
        scanf("%d", &x);
        s[i].erase(-x);
    }
    scanf("%d", &n);
    for (int k = 1; k < n; k++) {
        for (int i = 1; i <= 6; i++) {
            auto it = s[i].begin();
            s[i].erase(it);
        }
    }
    for (int i = 1; i <= 6; i++) {
        auto it = s[i].begin();
        printf("%d%c", -(*it), " \n"[i == 6]);
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}