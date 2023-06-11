#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, T, c[N], r[N];
map<int, int> mx, wh;

void upd(int col, int x, int id) {
	if (!mx.count(col)) mx[col] = x, wh[col] = id;
	else if (mx[col] < x) {
		mx[col] = x, wh[col] = id;
	}
} 

void solve() {
	bool p = 0;
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
    	cin >> c[i];
    	if (c[i] == T) p = 1;
    }
    for (int i = 1; i <= n; i++) {
    	cin >> r[i];
    	upd(c[i], r[i], i);
    }
    if (p) cout << wh[T] << '\n';
    else cout << wh[c[1]] << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}