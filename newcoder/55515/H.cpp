#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int u, v;

int getfa(int x) {
	for (int i = x - 1; i <= x + 1; i++) {
		if (i % 3 == 0) return i / 3;
	}
	return 233;
}
int getlca(int u, int v) {
	while (u != v) {
		if (u < v) swap(u, v);
		u = getfa(u);
		//printf("%d %d\n", u, v);
	}
	return v;
}

void solve() {
	int u, v;
	cin >> u >> v;
	cout << getlca(u, v) << '\n';
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}