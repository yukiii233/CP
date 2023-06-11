#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1500 + 5;

vector<int> G[N];
int n, m;
int dis[N], cnt[N];
bool vis[N];

bool spfa() {
	memset(vis, 0, sizeof vis);
	memset(cnt, 0, sizeof cnt);
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 1;
	vis[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int v : G[u]) {
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				if (++cnt[v] > n + 1) return 1;
				if (!vis[v]) q.push(v), vis[v] = 1;
			}
		}
	}
	return 0;
}
void print(vector<int> &v) {
	for (int x : v) cout << x << ' ';
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i <= m; i++) {
    	int u, v;
    	cin >> u >> v;
    	G[v].push_back(u);
    }
    if (spfa() || *max_element(dis + 1, dis + n + 1) == 0x3f3f3f3f) return cout << "INFINITE\n", void();
    int mx = *max_element(dis + 1, dis + n + 1);
    vector<int> val[mx + 1];
    cout << "FINITE\n";
    int res = 0;
    for (int i = 1; i <= n; i++) val[dis[i]].push_back(i), res += dis[i];
    cout << res << '\n';
    int now = 1;
    for (int i = 1; i <= mx; i++) {
    	for (int j = mx - now + 1; j <= mx; j++) print(val[j]);
    	now++;
    }
	cout << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}