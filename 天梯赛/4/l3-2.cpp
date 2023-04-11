#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
const int mod = 233334323;
const int N = 1e5 + 5;

const int M = 19260817;

int H[N], pow17[N], b[105][N], pow171[N], H1[N];
int n, m;
int a[N], num[N], p[N], re[N];
bool vis[N], to[N];
void Hash(int len) {
    for (int i = 1; i <= len; i++) {
        H[i] = (H[i - 1] * pow17[1] % M + a[i]) % M;
    }
}
int Hb(int x) {
    int res = 0;
    for (int i = 1; i <= num[x]; i++) {
        res = res * pow17[1] % M + b[x][i];
        res %= M;
    }
    return res;
}
int strH(int l, int r) {
    return (H[r] + M - pow17[r - l + 1] * 1ll * H[l - 1] % M) % M;
}
int strH1(int l, int r) {
    return (H1[r] + mod - pow171[r - l + 1] * 1ll * H1[l - 1] % mod) % mod;
}
void Hash1(int len) {
    for (int i = 1; i <= len; i++) {
        H1[i] = (H1[i - 1] * pow171[1] % mod + a[i]) % mod;
    }
}
int Hb1(int x) {
    int res = 0;
    for (int i = 1; i <= num[x]; i++) {
        res = res * pow171[1] % mod + b[x][i];
        res %= mod;
    }
    return res;
}
void down(int l, int r) {
    for (int i = l + 1; i <= r - 1; i++) vis[i] = 1;
}
bool chk(int l, int r) {
    for (int i = l; i <= r; i++) if (vis[i]) return 0;
    return 1;
}


void solve() {
    cin >> n;
    pow17[0] = 1;
    pow171[0] = 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < N; i++) pow17[i] = pow17[i - 1] *  17 % M, pow171[i] = pow171[i - 1] *  17 % mod;
    Hash(n);
    Hash1(n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> num[i];
        for (int j = 1; j <= num[i]; j++) cin >> b[i][j];
        p[i] = i;
    }
    sort(p + 1, p + n + 1, [](int x, int y) {
        return num[x] > num[y];
    });
    int cnt = m;
    for (int k = 1; k <= m; k++) {
        int x = p[k];
        int res = Hb(x), res1 = Hb1(x);
        for (int i = 1; i + num[x] - 1 <= n; i++) if (strH1(i, i + num[x] - 1) == res1 
        &&  1) {
            re[i] = x;
            down(i, i + num[x] - 1);
            cnt--;
            to[x] = 1;
            break;
        }
    }
    int rr = -1;
    if (cnt != 0) {
        for (int i = 1; i <= m; i++) if (to[i] == 0) {
            rr = i;
            break;
        }
        for (int i = 1; i <= n; i++) if (!re[i] && !vis[i]) {
            assert(re[i] == 0);
            re[i] = rr;
            break;
        }
        assert(rr != -1);
    }
    cnt = 1;
    cout << re[1];
    for (int i = 2; i <= n; i++) if (re[i]) {
        cout << ' ' << re[i];
        cnt++;
    }
    assert(cnt == m);
    cout << '\n';
}

signed main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
} 