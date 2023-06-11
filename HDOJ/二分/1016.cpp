#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e4 + 5;
ll dp[N][21], tmp[21];
int n, k, siz[N];
ll mid;
struct Edge {
	int v, a, b;
};
vector<Edge> G[N];

void dfs(int u, int fa) {
	memset(dp[u], 0, sizeof dp[u]);
	siz[u] = 1;
	for (Edge to : G[u]) {
		int v = to.v, a = to.a, b = to.b;
		if (v == fa) continue;
		dfs(v, u);
		fill(tmp, tmp + k + 1, mid + 1);
		for (int i = 0; i <= min(siz[u] - 1, k); i++) {
			for (int j = 0; j <= min(siz[v] - 1, k) && i + j <= k; j++) {
				if (dp[u][i] + dp[v][j] + b <= mid) 
					tmp[i + j] = min(tmp[i + j], max(dp[v][j] + b, dp[u][i]));
				if (j + i != k && dp[u][i] + dp[v][j] + a <= mid)
					tmp[i + j + 1] = min(tmp[i + j + 1], max(dp[v][j] + a, dp[u][i]));
			}
		}
		for (int i = 0; i <= k; i++) dp[u][i] = tmp[i];
		siz[u] += siz[v];
	}
}

void solve() {
    scanf("%d %d", &n, &k);
   	for (int i = 1; i <= n; i++) G[i].clear();
   	ll l = 0, r = 0;
    for (int i = 1; i < n; i++) {
    	int u, v, a, b;
    	scanf("%d %d %d %d", &u, &v, &a, &b);
    	r += max(a, b);
    	G[u].push_back({v, a, b});
    	G[v].push_back({u, a, b});
    }
    ll ans = -1;
    while (l <= r) {
    	mid = (l + r) >> 1;
    	dfs(1, 1);
    	if (dp[1][k] <= mid) r = mid - 1, ans = mid;
    	else l = mid + 1;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}