#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1000 + 5;

int n, sg[N];

int getmex(map<int, bool>& mp) {
	for (int i = 0; ; i++) {
		if (!mp.count(i)) return i;
	}
	return 233;
}

int main() {
	n = 1000;
	for (int i = 1; i <= n; i++) {
		map<int, bool> mp;
		for (int j = 1; j <= i; j++) {
			mp[sg[i - j]] = 1;
		}
		sg[i] = getmex(mp);
	}
	while (cin >> n && n) {
		int x, res = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			res ^= sg[x];
		}
		cout << (res ? "Rabbit Win!" : "Grass Win!") << '\n';
	}
	return 0;
}