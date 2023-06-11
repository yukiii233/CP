#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e6 + 5;

int n, k[N], dep[N];
ll sum[N];
char s[N];
vector<int> G[N];

void dfs(int u) {
	for (int v : G[u]) {
		dep[v] = dep[u] + 1;
		sum[v] = sum[u] + u;
		dfs(v);
	}
}

void solve() {
	scanf("%d %s", &n, s + 1);
	fill(sum, sum + n + 1, 0);
	for (int i = 0; i <= n; i++) G[i].clear();
	reverse(s + 1, s + n + 1);
	for (int i = 2; i <= n; i++) {
		int j = k[i - 1];
		while (j && s[j + 1] != s[i]) j = k[j];
		k[i] = j + (s[j + 1] == s[i]);
	}
	for (int i = 1; i <= n; i++)
		G[k[i]].push_back(i);
	dep[0] = 0;
	dfs(0);
	for (int i = 1; i <= n; i++) {
		ll res = dep[i] * 1ll * i - sum[i];
		printf("%lld ", res);
	}
	puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}