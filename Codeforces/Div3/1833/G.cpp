#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, cur[N];
vector<int> G[N];
bool dp[N][3];
map<pair<int, int>, vector<int> > mp;
map<pair<int, int>, int> Edge;
vector<int> ans;

void dfs(int u, int fa) {
	int sum = 0;
	bool flag = 0;
	vector<int> v1, v2;
	for (int v : G[u]) if (v != fa) {
		dfs(v, u);
		if (dp[v][1]) v1.push_back(v);
		if (dp[v][2]) v2.push_back(v);
		if (dp[v][0]) sum += 0;
		else if (dp[v][1]) sum++;
		else if (dp[v][2]) sum += 2;
		else flag = 1;
	}
	if (flag || sum > 2) return;
	if (sum == 0) {
		dp[u][1] = 1;
		if (!v2.empty()) {
			dp[u][0] = 1;
			int v = v2[0];
			mp[{u, 0}].push_back(u);
			mp[{u, 0}].insert(mp[{u, 0}].end(), mp[{v, 2}].begin(), mp[{v, 2}].end());
		} else if (v1.size() > 1) {
			dp[u][0] = 1;
			mp[{u, 0}].push_back(u);
			mp[{u, 0}].push_back(v1[0]);
			mp[{u, 0}].push_back(v1[1]);
		}
		if (!v1.empty()) {
			dp[u][2] = 1;
			mp[{u, 2}].push_back(u);
			mp[{u, 2}].push_back(v1[0]);
		}
	} else if (sum == 1) {
		dp[u][2] = 1;
		mp[{u, 2}].push_back(u);
		mp[{u, 2}].push_back(v1[0]);
		if (v1.size() > 1) {
			dp[u][0] = 1;
			mp[{u, 0}].push_back(u);
			mp[{u, 0}].push_back(v1[0]);
			mp[{u, 0}].push_back(v1[1]);
		}
	} else {
		dp[u][0] = 1;
		if (!v2.empty()) {
			int v = v2[0];
			mp[{u, 0}].push_back(u);
			mp[{u, 0}].insert(mp[{u, 0}].end(), mp[{v, 2}].begin(), mp[{v, 2}].end());
		} else {
			mp[{u, 0}].push_back(u);
			mp[{u, 0}].push_back(v1[0]);
			mp[{u, 0}].push_back(v1[1]);
		}
	}
}
void print(int u, int fa) {
	if (cur[u] == 0 && u != 1) ans.push_back(Edge[{u, fa}]);
	if (cur[u] == 0) {
		int det = 3 - (int)mp[{u, 0}].size() + 1;
		for (int v : mp[{u, 0}]) if (v != u) {
			cur[v] = det; 
		}
	} else if (cur[u] == 2) {
		for (int v : mp[{u, 2}]) if (v != u) {
			cur[v] = 1;
		}
	}
	for (int v : G[u]) if (v != fa) {
		print(v, u);
	}
}

void solve() {
	mp.clear();
	Edge.clear();
	ans.clear();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = dp[i][2] = 0, G[i].clear(), cur[i] = 0;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		Edge[{u, v}] = Edge[{v, u}] = i;
	}
	dfs(1, 1);
	if (!dp[1][0]) return puts("-1"), void();
	print(1, 1);
	printf("%d\n", (int)(ans.size()));
	for (int x : ans) printf("%d ", x);
	puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}