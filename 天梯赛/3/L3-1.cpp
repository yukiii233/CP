#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 200 + 5;

int n, m, k;
int dis[N][N], cost[N][N];
map<int, int> r[N];
int mm[1555];
bool G[N][N];
string s;
bool vis[N];
int res;
int rr[N];

void dfs(int u) {
    vis[u] = 1;
    rr[++res] = u;
    for (int i = 1; i <= n; i++) if (!vis[i] && G[u][i]) {
        dfs(i);
    }
}

void solve() {
    cin >> n >> m >> k;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    getline(cin, s);
    for (int i = 1; i <= m; i++) {
        getline(cin, s);
        stringstream ss(s);
        int last = 0, cur = 1, cc;
        while (ss >> s) {
            int now = stoi(s);
            if (last == 0) {
                last = now;
                continue;
            }
            cur ^= 1;
            if (cur == 0) cc = now;
            else {
                dis[last][now] = dis[now][last] = min(dis[now][last], cc);
                last = now;
            }
        }
        mm[i] = last;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) if (dis[i][j] != 0x3f3f3f3f) {
            
            cost[i][j] = dis[i][j] / k;
            if (!r[i].count(cost[i][j])) {
                r[i][cost[i][j]] = j;
            } else if (dis[i][r[i][cost[i][j]]] < dis[i][j]) {
                r[i][cost[i][j]] = j;
            }
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (dis[i][mm[j]] != 0x3f3f3f3f) G[i][mm[j]] = 1;
        for (auto [x , v] : r[i]) G[i][v] = 1;
        for (int j = 1; j <= n; j++) if (G[i][j]) {
           // printf("%d -> %d\n", i, j);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int S;
        cin >> S;
        memset(vis, 0, sizeof vis);
        res = 0;
        dfs(S);
        sort(rr + 1, rr + res + 1);
        int ff = 0;
        for (int i = 1; i <= res; i++) {
            if (ff) cout << ' ';
            else ff = 1;
            cout << rr[i];
        }
        cout << '\n';
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}