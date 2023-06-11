#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 100 + 5;

int n, m;
vector<int> G[N];
bool vis[N];

void read(int u) {
	int num, x;
	cin >> num;
	if (num == -1) exit(1);
	while (num--) {
		cin >> x;
		if (!vis[u]) G[u].push_back(x);
	}
}
void dfs(int u, int fr) {
	cout << u << endl;
	if (u == n) {
		string s;
		cin >> s;
		exit(0);
	}
	read(u);
	vis[u] = 1;
	for (int v : G[u]) if (!vis[v] && v != fr) {
		dfs(v, u);
	}
	cout << fr << endl;
	read(fr);
}

void solve() {
	cin >> n >> m;
	read(1);
	vis[1] = 1;
	for (int v : G[1]) dfs(v, 1);
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}