#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 100 + 5;
const double eps = 1e-8;

int n;
vector<int> G[N * 2];
bool mark[N * 2];
int stk[N], top;
double dis[N][N][2][2];

double dist(double x1, double y1, double x2, double y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
struct Point {
	double x, y;
} a[N][2];

void build_G(double x) {
	top = 0;
	memset(mark, 0, sizeof mark);
	for (int i = 1; i <= n + n + 1; i++) G[i].clear(); 
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int l = 0; l < 2; l++) {
				for (int r = 0; r < 2; r++) {
					if (dis[i][j][l][r] + eps < 4 * x) {
						G[i * 2 + l].push_back(j * 2 + (r ^ 1));
						G[j * 2 + r].push_back(i * 2 + (l ^ 1));
					}
				}
			}
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
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j < 2; j++) scanf("%lf %lf", &a[i][j].x, &a[i][j].y);
    }
	double l = 0, r = 0, ans = 0.0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int l = 0; l < 2; l++) {
				for (int rr = 0; rr < 2; rr++) 
					dis[i][j][l][rr] = dist(a[i][l].x, a[i][l].y, a[j][rr].x, a[j][rr].y), r = max(r, dis[i][j][l][rr]);
			}
		}
	}
	while (l + eps < r) {
		double mid = (l + r) / 2;
		build_G(mid);
		if (two_sat()) l = mid + eps, ans = mid;
		else r = mid - eps;
	}
	printf("%.2lf\n", sqrt(ans));
}

int main() {
    while (~scanf("%d", &n)) {
        solve();
    }
    return 0;
}