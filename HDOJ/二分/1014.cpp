#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 200 + 5, M = 10005;

int n, m;
vector<int> G[N * 2];
bool mark[N * 2];
int stk[N], top;
int a[M], b[M], c[M];
void build_G(int mid) {
	memset(mark, 0, sizeof mark);
	top = 0;
	for (int i = 1; i <= n * 2 + 1; i++) G[i].clear();
    for (int i = 1; i <= mid; i++) {
    	int u = a[i], v = b[i];
    	if (c[i] == 2) {
    		G[2 * u + 1].push_back(2 * v);
    		G[2 * v + 1].push_back(2 * u);
    	} else if (c[i] == 1) {
    		G[2 * u + 1].push_back(2 * v + 1);
    		G[2 * v + 1].push_back(2 * u + 1);
    		G[2 * u].push_back(2 * v);
    		G[2 * v].push_back(2 * u);
    	} else {
    		G[2 * u].push_back(2 * v + 1);
    		G[2 * v].push_back(2 * u + 1);
    	}
    }
}
bool dfs(int u) {
    if (mark[u ^ 1]) return false;
    if (mark[u]) return true;
    mark[u] = 1;
    stk[++top] = u;
    for (int v : G[u]) {
        if (!dfs(v)) return false;
    }
    return true;
}
bool two_sat() {
    for (int i = 1; i <= n; i++) {
        if (!mark[i * 2] && !mark[i * 2 + 1]) {
            top = 0;
            if (!dfs(2 * i)) {
                while (top) mark[stk[top--]] = 0;
                if (!dfs(2 * i + 1)) return 0;
            }
        }
    }
    return 1;
}


void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &a[i], &b[i], &c[i]), a[i]++, b[i]++;
	int l = 1, r = m, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		build_G(mid);
		if (two_sat()) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}