#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 10 + 5;

int n, m, p, k, s, ans = inf;
int dp[N][N][1 << 11], door[N][N][N][N];
vector<int> key[N][N];
int dx[5] = {1, 0, -1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};
bool vis[N][N][1 << 11];

struct node {
	int x, y, s;
};
void get(int &x, int k) {
	x |= (1 << (k - 1));
}
bool check(int x, int k) {
	return ((x >> (k - 1)) & 1);
}
void print(int x) {
	static int stk[10];
	int top = 0;
	while (x) {
		stk[++top] = x & 1;
		x >>= 1;
	}
	while (top) printf("%d", stk[top--]);
	puts("");
}

node fr[N][N][1 << 11];

void print(int x, int y, int cur) {
	if (x == 0) return;
	auto [fx, fy, fc] = fr[x][y][cur];
	print(fx, fy, fc);
	printf("* %d %d %d ", x, y, dp[x][y][cur]);
	print(cur);
}

void spfa() {
	queue<node> q;
	q.push({1, 1, 0});
	dp[1][1][0] = 0;
	vis[1][1][0] = 1;
	while (!q.empty()) {
		auto [x, y, cur] = q.front();
		q.pop();
		if (x == n && y == m) ans = min(ans, dp[x][y][cur]);
		vis[x][y][cur] = 0;
		for (int k = 0; k < 5; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			if (door[x][y][nx][ny] == 0) continue;
			if (door[x][y][nx][ny] != -1 && !check(cur, door[x][y][nx][ny])) continue;
			int ncur = cur;
			if (key[nx][ny].size()) {
				for (int x : key[nx][ny]) {
					get(ncur, x);
				}
			}
			if (dp[nx][ny][ncur] > dp[x][y][cur] + 1) {
				dp[nx][ny][ncur] = dp[x][y][cur] + 1;
				fr[nx][ny][ncur] = {x, y, cur};
				if (!vis[nx][ny][ncur]) {
					q.push({nx, ny, ncur});
					vis[nx][ny][ncur] = 1;
				}
			}
		}
	}
}

void solve() {
	memset(dp, 0x3f, sizeof dp);
	memset(door, -1, sizeof door);
	scanf("%d %d %d %d", &n, &m, &p, &k);
	for (int i = 1; i <= k; i++) {
		int X1, Y1, X2, Y2, g;
		scanf("%d %d %d %d %d", &X1, &Y1, &X2, &Y2, &g);
		door[X1][Y1][X2][Y2] = g;
		door[X2][Y2][X1][Y1] = g;
	}
	scanf("%d", &s);
	for (int i = 1; i <= s; i++) {
		int x, y, g;
		scanf("%d %d %d", &x, &y, &g);
		key[x][y].push_back(g);
	}
	spfa();
	if (ans == inf) ans = -1;
	printf("%d\n", ans);
	//print(4, 4, 3);
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}