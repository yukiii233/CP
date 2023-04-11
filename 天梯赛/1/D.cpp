#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
unsigned long long x;

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);
    x = 1;
    for (unsigned long long i = 1; i <= a + b; i++) x *= i;
    printf("%llu\n", x);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}