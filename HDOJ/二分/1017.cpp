#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 1000 + 5;

int n, m, mid;
int dp[N];
vector<pair<int, int> > G[N];

void dfs(int u, int fa) {
	bool f = 1;
	for (auto to : G[u]) {
		int v = to.first, w = to.second;
		if (v == fa) continue;
		if (f) f = 0, dp[u] = 0;
		dfs(v, u);
		if (w <= mid) dp[u] += min(w, dp[v]);
		else if (dp[v] == inf) {
			dp[u] = inf;
			break;
		} else dp[u] += dp[v];
	}
}

void solve() {
    for (int i = 1; i <= n; i++) G[i].clear(), dp[i] = inf;
    for (int i = 1; i < n; i++) {
    	int u, v, w;
    	scanf("%d %d %d", &u, &v, &w);
    	G[u].push_back({v, w});
    	G[v].push_back({u, w});
    }
    int l = 0, r = 1001, ans = -1;
    while (l <= r) {
    	mid = (l + r) >> 1;
    	dfs(1, 1);
    	if (dp[1] <= m) r = mid - 1, ans = mid;
    	else l = mid + 1;
    }
    printf("%d\n", ans);
}

int main() {
    while (~scanf("%d %d", &n, &m) && (n + m)) {
        solve();
    }
    return 0;
}