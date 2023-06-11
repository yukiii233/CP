#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100;
int dp[N][N][2];

int dfs(int x, int y, int who) {
	if (x == 0 || y == 0) {
		return 1;
	}
	int re = 1;
	for (int i = 1; i <= min(3, x); i++) {
	//	if (x == 2 && y == 2) printf("%d %d %d\n", x - i, y, dfs(x - i, y, who ^ 1));
		re &= dfs(x - i, y, who ^ 1);
	}
	for (int i = 1; i <= min(3, y); i++) {
	//	if (x == 2 && y == 2) printf("%d %d %d\n", x, y - i, dfs(x, y - i, who ^ 1));
		re &= dfs(x, y - i ,who ^ 1);
	}
	return re == 0;
}

int main() {
	// init();
	for (int i = 1; i <= 10; i++) {
		for (int j = i; j <= 10; j++) {
			if (dfs(i, j, 0) == 1) printf("%d %d\n", i, j);
		}
	}
}