#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

char a, b;
int s[20];

void solve() {
	s[1] = 3, s[2] = 4, s[3] = 8, s[4] = 9, s[5] = 14, 
	s[6] = 23;
	scanf("%c %c", &a, &b);
	if (a > b) swap(a, b);
	printf("%d\n", s[b - 'A'] - s[a - 'A']);
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}