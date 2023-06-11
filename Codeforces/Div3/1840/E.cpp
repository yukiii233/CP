#include <bits/stdc++.h>
using namespace std;

const int mod = 19260817;
const int N = 2e5 + 5;

int n;
long long po[N], ha, hb;

int t, q;
char s[3][N];

struct Op {
	int pos, v1, v2;
};

void change(int n1, int pos, long long ori, long long cur) {
	if (n1 == 1) {
		ha = (ha - po[pos] * ori % mod) % mod;
		ha += mod;
		ha %= mod;
		ha += po[pos] * cur % mod;
		ha %= mod;
	} else {
		hb = (hb - po[pos] * ori % mod) % mod;
		hb += mod;
		hb %= mod;
		hb += po[pos] * cur % mod;
		hb %= mod;
	}
	
}

void solve() {
	ha = hb = 0;
	scanf("%s %s", s[1] + 1, s[2] + 1);
	n = strlen(s[1] + 1);
	scanf("%d %d", &t, &q);
	vector<Op> v(q + t + 1);
	for (int i = 1; i <= n; i++) ha += (s[1][i] - 'a') * po[i] % mod, ha %= mod;
	for (int i = 1; i <= n; i++) hb += (s[2][i] - 'a') * po[i] % mod, hb %= mod;
	for (int i = 1; i <= q; i++) {
		int op;
		scanf("%d", &op);
		if (v[i].pos != 0) {
			change(1, v[i].pos, s[1][v[i].pos] - 'a', v[i].v1);
			change(2, v[i].pos, s[2][v[i].pos] - 'a', v[i].v2);
			s[1][v[i].pos] = v[i].v1 + 'a';
			s[2][v[i].pos] = v[i].v2 + 'a';
		}
		if (op == 1) {
			int pos;
			scanf("%d", &pos);
			v[i + t] = {pos, s[1][pos] - 'a', s[2][pos] - 'a'};
			change(1, pos, s[1][pos] - 'a', 'z' - 'a');
			change(2, pos, s[2][pos] - 'a', 'z' - 'a');
			s[1][pos] = 'z';
			s[2][pos] = 'z';
		} else if (op == 2) {
			int n1, n2, p1, p2;
			scanf("%d %d %d %d", &n1, &p1, &n2, &p2);
			change(n1, p1, s[n1][p1], s[n2][p2]);
			change(n2, p2, s[n2][p2], s[n1][p1]);
			swap(s[n1][p1], s[n2][p2]);
		} else {
			ha == hb ? puts("YES") : puts("NO");
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	po[0] = 1;
	for (int i = 1; i < N; i++)
		po[i] = po[i - 1] * 29 % mod;
	while (T--) {
		solve();
	}
	return 0;
}