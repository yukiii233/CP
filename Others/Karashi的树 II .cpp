// https://ac.nowcoder.com/acm/contest/57071/F
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
vector<int> G[N];
int n, siz[N], a[N], son[N], faz[N], d[N], det, lim;
ll ans;

int tr[N * 2];
int lowbit(int x) {
	return x & -x;
}

void add(int x, int v) {
	x += det;
	for (int i = x; i <= lim; i += lowbit(i)) {
		tr[i] += v;
	}
}
int qry1(int x) {
	int res = 0;
	x += det;
	for (int i = x; i; i -= lowbit(i)) {
		res += tr[i];
	}
	return res;
}
int qry(int x) {
	return qry1(n) - qry1(x - 1);
}

ll calc(int u, int fa, ll ini) {
	ll res = qry(ini - d[u]);
	for (int v : G[u]) if (v != fa) {
		res += calc(v, u, ini);
	}
	return res;
}
void pushdown(int u, int fa, int x) {
	add(d[u], x);
	for (int v : G[u]) if (v != fa) {
		pushdown(v, u, x);
	}
}

void dfs1(int u, int fa) {
    siz[u] = 1;
    son[u] = -1;
    faz[u] = fa;
    d[u] = d[fa] + a[u];
    for (int v : G[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[son[u]] < siz[v]) son[u] = v;
    }
}
void dfs(int u, int fa, int tp) {
	for (int v : G[u]) if (v != fa && v != son[u]) {
		dfs(v, u, 0);
	}
	if (son[u] != -1) dfs(son[u], u, 1);
	for (int v : G[u]) if (v != fa && v != son[u]) {
		ans += calc(v, u, d[u] + d[faz[u]]);
		pushdown(v, u, 1);
	}
	ans += qry(d[fa]);
	if (tp == 0) {
		for (int v : G[u]) if (v != fa) {
			pushdown(v, u, -1);
		}
	} else add(d[u], 1);
}

int main() {
	cin >> n;
	det = n + 1, lim = n + n + 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) a[i] = -1;
		else ans++;
	}	
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0);
	dfs(1, 0, 1);
	cout << ans << '\n';
	return 0;
}