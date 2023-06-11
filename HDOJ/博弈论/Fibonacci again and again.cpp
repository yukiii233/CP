#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1000 + 5;

int n, sg[N], f[N];

int getmex(map<int, bool>& mp) {
	for (int i = 0; ; i++) {
		if (!mp.count(i)) return i;
	}
	return 233;
}

int main() {
	n = 1000;
	f[1] = 1, f[2] = 2;
	int cnt = 3;
	while (true) {
		f[cnt] = f[cnt - 1] + f[cnt - 2];
		if (f[cnt] > n) break;
		cnt++;
	}
	for (int i = 1; i <= n; i++) {
		map<int, bool> mp;
		for (int j = 1; f[j] <= i; j++) {
			mp[sg[i - f[j]]] = 1;
		}
		sg[i] = getmex(mp);
	}
	int m, p;
	while (cin >> m >> n >> p) {
		if (m == 0 && n == 0 && p == 0) break;
		cout << ((sg[m] ^ sg[n] ^ sg[p]) == 0 ? "Nacci" : "Fibo") << '\n';
	}
	return 0;
}