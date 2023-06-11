#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 100 + 5; 

int m, a[N];

void solve() {
	int sum = 0;
	for (int i = 1; i <= m; i++) scanf("%d", &a[i]), sum ^= a[i];
	int res = 0;
	for (int i = 1; i <= m; i++) {
		sum ^= a[i];
		res += sum < a[i];
		sum ^= a[i];
	}
	printf("%d\n", res);
}

int main() {
	while (scanf("%d", &m) == 1 && m) {
		solve();
	}
}