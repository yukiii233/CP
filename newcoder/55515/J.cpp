#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 5;
int l, r;
int q, L, R;

int tr[N], a[N];
int lowbit(int x) {
	return x & -x;
}
void add(int x, int v) {
	if (x < 1) return;
	for (int i = x; i < N; i += lowbit(i)) 
		tr[i] += v;
}
int qry(int x) {
	if (x <= 0) return 0;
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) {
		res += tr[i];
	}
	return res;
}

void solve() {
	 R = max(R, L);
	 for (int i = L; i <= R; i++) {
	 	add(i, -qry(i) + qry(i - 1));
	 }
	scanf("%d", &q);
	L = R = 1e6;
	R--;
	map<int, vector<int>> mp;
	while (q--) {
		char op[6];
		int x;
		scanf("%s %d", op, &x);
		if (op[0] == 'F') {
			a[--L] = x;
			mp[x].push_back(L);
		}
		if (op[0] == 'B') {
			a[++R] = x;
			mp[x].push_back(R);
		}
		if (op[0] == 'D') {
			if (!mp.count(x) || mp[x].empty()) continue;
			int pos = mp[x][(int)(mp[x].size()) - 1];
			mp[x].pop_back();
			add(pos, -1);
		}
		if (op[0] == 'Q') {
			int l = L, r = R, ans = -1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				//printf("%d %d\n", mid - L + 1, mid - L + 1 + qry(mid));
				if (mid - L + 1 + qry(mid) >= x) {
					r = mid - 1;
					ans = a[mid];
				} else l = mid + 1;
			}
			printf("%d\n", ans);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}