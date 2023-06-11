#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define int long long
const int N = 2e5 + 5;
int n, m, w;
char s[N];
int dis[30][30];

int calc(int x, int y) {
	if (x == y) return 0;
	int res = w;
	if (dis[y][x] != -1) res = min(res, dis[y][x]);
	if (dis[x][y] != -1) res = min(res, dis[x][y]);
	for (int i = 1; i <= 26; i++) if (dis[x][i] != -1 && dis[y][i] != -1) {
		res = min(res, dis[x][i] + dis[y][i]);
	}
	return res;
}

void solve() {
	scanf("%lld %lld %lld", &n, &m, &w);
	scanf("%s", s + 1);
	memset(dis, -1, sizeof dis);
	for (int i = 1; i <= m; i++) {
		char a[6], b[6];
		int cc;
		scanf("%s %s %lld", a, b, &cc);
		if (dis[a[0] - 'a' + 1][b[0] - 'a' + 1] == -1) dis[a[0] - 'a' + 1][b[0] - 'a' + 1] = cc; 
		else dis[a[0] - 'a' + 1][b[0] - 'a' + 1] = min(dis[a[0] - 'a' + 1][b[0] - 'a' + 1], cc);
	}
	for (int k = 1; k <= 26; k++) {
		for (int i = 1; i <= 26; i++) {
			for (int j = 1; j <= 26; j++) {
				if (dis[i][k] == -1 || dis[k][j] == -1) continue;
				if (dis[i][j] == -1) dis[i][j] = dis[i][k] + dis[k][j];
				else dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int j = n - i + 1;
		if (i >= j) break;
		res += calc(s[i] - 'a' + 1, s[j] - 'a' + 1);
	}
	printf("%lld\n", res);
}

signed main() {
	int T;
	scanf("%lld", &T);
	while (T--) {
		solve();
	}
}