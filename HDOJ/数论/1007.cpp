#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e6 + 5;

int P[N], pcnt;
ll phi[N];
bool vis[N];

void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            P[++pcnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= pcnt && i * P[j] <= n; j++) {
            vis[i * P[j]] = 1;
            if (i % P[j] != 0) {
                phi[i * P[j]] = phi[i] * phi[P[j]];
            } else {
                phi[i * P[j]] = phi[i] * P[j];
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) phi[i] += phi[i - 1]; 
}

int l, r;

void solve() {
    printf("%lld\n", phi[r] - phi[l - 1]);
}

int main() {
    init(3e6);
    while (~scanf("%d %d", &l, &r)) {
        solve();
    }
    return 0;
}