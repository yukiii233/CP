#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int mx, a[5], limit, delta;

void solve() {
    for (int i = 1; i <= 4; i++) scanf("%d", &a[i]), mx = max(a[i], mx);
    scanf("%d %d", &limit, &delta);
    vector<int> v;
    for(int i = 1; i <= 4; i++) {
        if (a[i] < limit || mx - a[i] > delta) v.push_back(i);
    }
    if (v.empty()) puts("Normal");
    else if (v.size() == 1) printf("Warning: please check #%d!\n", v[0]);
    else puts("Warning: please check all the tires!");
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}