#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 100 + 5;

int n, k, a, b, c, ans = 0x3f3f3f3f, dd;
int dp[N][N][15];
bool mp[N][N], vis[N][N][15];
struct node {
	int x, y, d;
};
node fr[N][N][15];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void print(int x, int y, int cur) {
	if (x == 0) return;
	auto [fx, fy, fc] = fr[x][y][cur];
	print(fx, fy, fc);
	printf("* %d %d %d %d\n", x, y, cur, dp[x][y][cur]);
}

void spfa() {
	dp[1][1][k] = 0;
	queue<node> q;
	q.push({1, 1, k});
	vis[1][1][k] = 1;
	while (!q.empty()) {
		auto [x, y, d] = q.front();
		q.pop();
		if (x == y && x == n && dp[x][y][d] < ans) ans =dp[x][y][d], dd = d;
		vis[x][y][d] = 0;
		for (int K = 0; K < 4; K++) {
			int nx = x + dx[K], ny = y + dy[K];
			if (nx > n || nx < 1 || ny > n || ny < 1) continue;
			int nd = d - 1, res = 0;
			if (K > 1) res = b;
			if (d == 0) nd = k - 1, res += a + c;
			if (mp[nx][ny]) nd = k, res += a;
			if (dp[nx][ny][nd] > dp[x][y][d] + res) {
				dp[nx][ny][nd] = dp[x][y][d] + res;
				fr[nx][ny][nd] = {x, y, d};
				if (!vis[nx][ny][nd]) {
					q.push({nx, ny, nd});
					vis[nx][ny][nd] = 1;
				}
			}
		}
	}
}

void solve() {
	scanf("%d %d %d %d %d", &n, &k, &a, &b, &c);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) scanf("%d", &mp[i][j]);
	memset(dp, 0x3f, sizeof dp);
	spfa();
	printf("%d\n", ans);
	//print(n, n, dd);
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}