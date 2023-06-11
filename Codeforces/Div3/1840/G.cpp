#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get() {
	return rng() % N;
}
int pos[N], det, mov, x, n, num;

int query(char ch, int x) {
	cout << ch << ' ' << x << endl;
	int res;
	cin >> res;
	return res; 
}

void solve() {
	cin >> x;
	for (int i = 1; i <= 397; i++) {
		mov = get();
		det += mov;
		num = query('+', mov);
		n = max(n, num);
	}
	int d = 300;
	query('-', det);
	det = n - 1;
	num = query('+', n - 1);
	for (int i = 1; i <= d; i++) {
		det++;
		num = query('+', 1);
		if (num == x) {
			cout << "! " << n + i - 1 << endl;
			return;
		}
		pos[num] = n + i;
	}
	query('-', det);
	det = 0;
	while (233) {
		num = query('-', d);
		det += d;
		if (pos[num]) {
			cout << "! " << pos[num] + det - 1 << endl;
			return;
		}
	}
	puts("233");
	return;
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}