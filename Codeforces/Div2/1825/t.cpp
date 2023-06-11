#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

bool check(int x) {
	if (x <= 1) return 0;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}


int main() {
	int res = 0;
	for (int i = 1; i * i <= 1e9; i++) {
		res += check(i);
	}
	printf("%d\n", res);
}