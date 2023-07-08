#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 20 + 5;

int b[N], lb[N], n, a[N * 10];

void solve() {
	memset(b, 0, sizeof b);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]]++;
	}
	cout << "- 0" << endl;
	cout << endl;
	for (int k = 1; k <= 5; k++) {
		memcpy(lb, b, sizeof lb);
		memset(b, 0, sizeof b);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			b[a[i]]++;
		}
		int q = 0, wh = 0;
		for (int i = 1; i <= 20; i++) if (b[i] > lb[i]) {
			for (int j = 1; j <= 20; j++) if (j != i) q += b[j];
			wh = i;
			break;
		}
		if (n ==1 || b[wh] == 1) {
			cout << "! ";
			for (int i = 1; i <= n; i++) if (wh == a[i]) {
				cout << i << endl;
				cout << endl;
				return;
			}
		}
		cout << "- " << q;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (wh && wh != a[i]) cout << ' ' << i, cnt++; 
		}
		assert(cnt == q);
		cout << endl;
		cout << endl;
		n -= q;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}