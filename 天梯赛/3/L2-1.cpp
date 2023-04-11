#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e4+ 5;

int A, B;
bool del[N], in[N];

bool check(int x) {
    if (x == 2) return 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int calc(int x) {
    int res = 0;
    while (x) {
        int u = x % 10;
        res += u * u;
        x /= 10;
    }
    return res;
}

void solve() {
    cin >> A >> B;
    for (int i = A; i <= B; i++) {
        map<int, bool> r;
        int x = i;
        while (x != 1) {
            if (r.count(x) || del[x]) {
                in[i] = 1;
                del[i] = 1;
                break;
            }
            if (x != i) in[x] = 1;
            r[x] = 1;
            x = calc(x);  
        }
    }
    bool pd = 0;
    for (int i = A; i <= B; i++) if (!in[i]) {
        int cnt = 0;
        int x = i;
        while (x != 1) {
            cnt++;
            x = calc(x);
        }
        if (check(i)) cnt *= 2;
        pd = 1;
        cout << i << ' ' << cnt << '\n';
    }
    if (!pd) cout << "SAD" << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}