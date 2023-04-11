#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n;
int a[N];
vector<int> d[N];

void build(int l, int r, int dep) {
    if (l > r) return;
    d[dep].push_back(a[r]);
    if (l == r) return;
    for (int k = 0; r - ((1 << k) - 1) - 1 >=  l; k++) {
        int r1 = r - ((1 << k) - 1) - 1;
        int x = (1 << k) - 1, y = 1 << k;
        if (r - l - 2 * x < 0) break;
        if (r - l - 2 * x <= y) {
            build(l, r1, dep + 1), build(r1 + 1, r - 1, dep + 1);
            break;
        } else if (r - l - 2 * x <= 2 * y) {
            build(l, l + x + y - 1, dep + 1), build(l + x + y, r - 1,  dep + 1);
            break;
        }
    }
    return;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, n,1);
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        for (int x : d[i]) {
            if (flag) putchar(' ');
            else flag =1;
            printf("%d", x);
        }
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}