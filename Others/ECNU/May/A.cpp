#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e6 + 5;

int n;

void solve() {
	cin >> n;
	cout << (int)(log2(n)) + 1 << '\n';
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
}