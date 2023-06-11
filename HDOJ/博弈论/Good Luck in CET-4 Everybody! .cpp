#include <iostream>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1000 + 5;

int n, dp[N];

void solve() {
	
}

int main() {
	n = 1000;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int j = 1;
		dp[i] = 1;
		while (j <= i) {
			dp[i] &= dp[i - j];
			j <<= 1;
		}
		dp[i] ^= 1;
	}
	while (cin >> n) {
		cout << (dp[n] ? "Kiki" : "Cici") << '\n';
	}
	return 0;
}