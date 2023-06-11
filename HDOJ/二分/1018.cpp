#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m, k, res;
int fa[N];

int getfa(int x) {
	return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
void merge(int u, int v) {
	u = getfa(u), v = getfa(v);
	if (u == v) return;
	fa[u] = v;
}

struct Edge {
	int u, v, w, b;
} e[N << 1], ee[N << 1];

int check(int mid) {
	for (int i = 1; i <= m; i++) {
		if (e[i].b == 0) ee[i] = e[i], ee[i].w += mid;
		else ee[i] = e[i];
	}
	sort(ee + 1, ee + m + 1, [](Edge x,  Edge y) {
		return x.w == y.w ? x.b < y.b : x.w < y.w;
	});
	iota(fa + 1, fa + n + 1, 1);
	int cnt = 0, wcnt = 0;
	res = 0;
	for (int i = 1; i <= m; i++) {
		int u = ee[i].u, v = ee[i].v;
		if (getfa(u) == getfa(v)) continue;
		merge(u, v);
		res += ee[i].w;
		cnt++;
		if (ee[i].b == 0) wcnt++;
		if (cnt == n - 1) break;
	}
	return wcnt;
}

void solve() {
    for (int i = 1; i <= m; i++) {
    	scanf("%d %d %d %d", &e[i].u, &e[i].v, &e[i].w, &e[i].b);
    	e[i].u++, e[i].v++;
    }
    static int Case = 0;
    printf("Case %d: ", ++Case);
    int l = -105, r = 105, ans = -1;
    while (l <= r) {
    	int mid = (l + r) >> 1;
    	int tmp = check(mid);
    	if (tmp >= k) l = mid + 1, ans = res - k * mid;
    	else r = mid - 1;
    }
    printf("%d\n", ans);
}

int main() {
    while (~scanf("%d %d %d", &n, &m, &k)) {
        solve();
    }
    return 0;
}