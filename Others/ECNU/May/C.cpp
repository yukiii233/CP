#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, a[N], b[N], t[N];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &t[i], &a[i], &b[i]);
		a[i] -= t[i];
		b[i] -= t[i];
		t[i] = a[i] - b[i];
	}
	priority_queue<int> q;
	int s = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		s += b[i], res++;
		q.push(t[i]);
		while (res && s < 0) {
			s += q.top();
			q.pop();
			res--;
		}
		if (s < 0) return puts("-1"), void();
	}
	printf("%d\n", res);
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
}