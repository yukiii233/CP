#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n, m;

void solve() {
    scanf("%d %d", &n, &m);
    printf("%d\n", n / m);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}