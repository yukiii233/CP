#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
const int mod = 998244353;
const int N = 2e5 + 5;

int n, m, q;
ll a[N];

struct Dist {
    vector<pair<int, int> > G[N];
    ll dis[N];
    bool vis[N];
    void dij(int s) {
        priority_queue<pair<ll, int>> q;
        fill(dis + 1, dis + n + 1, 1e17);
        dis[s] = 0;
        q.push({0, s});
        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [v, w] : G[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({-dis[v], v});
                }
            }
        }
     }
     
} f, s;

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        f.G[u].push_back({v, c});
        s.G[v].push_back({u, d});  
    }
    f.dij(1);
    s.dij(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    multiset<ll> ss;
    for (int i = 1; i <= n; i++) {
        if (f.dis[i] != 1e17 && s.dis[i] != 1e17) ss.insert(f.dis[i] + (s.dis[i] - 1) / a[i] + 1);  
    }
    while (q--) {
        int i;
        ll w;
        cin >> i >> w;
        if (f.dis[i] == 1e17 || s.dis[i] == 1e17) {
            cout << *ss.begin() << '\n';
            continue;
        }
        ss.erase(ss.lower_bound((ll)(f.dis[i] + (s.dis[i] - 1) / a[i] + 1)));
        a[i] = w;
        ss.insert(f.dis[i] + (s.dis[i] - 1) / a[i] + 1);
        cout << *ss.begin() << '\n';
    }
}

signed main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}