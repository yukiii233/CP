#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 10 + 5;

int n, res, a[N];
bool book[N];

int getmex(map<int, bool> &mp) {
	for (int i = 0; i <= n; i++) if (!mp.count(i)) return i; 
	return n + 1;
}

void dfs(int p) {
	if (p == n + 1) {
		map<int, bool> mp;
		for (int i = 1; i <= n; i++) if (book[i]) {
			mp[a[i]] = 1;
			if (a[i] - getmex(mp) > 1) return;
		}
		res++;
		return;
	}
	book[p] = 1;
	dfs(p + 1);
	book[p] = 0;
	dfs(p + 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout << res - 1 << '\n';
	return 0;
}