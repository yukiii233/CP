#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;

#define lson (p << 1)
#define rson (p << 1 | 1)
#define mid ((l + r) >> 1)
int tr[N << 2], tag[N << 2];
int n, a[N];

void build(int p, int l, int r) {
	tag[p] = 0;
	tr[p] = -inf;
	if (l == r) {
		tr[p] = a[l] - l + 1;
		return;
	}
	build(lson, l, mid);
	build(rson, mid + 1, r);
	tr[p] = max(tr[lson], tr[rson]);
}
void pushdown(int p) {
	if (tag[p] == 0) return;
	tag[lson] = tag[rson] = tag[p];
	tr[lson] += tag[p];
	tr[rson] += tag[p];
	tag[p] = 0;
}
void modify(int p, int l, int r, int L, int R, int v) {
	if (l > R || r < L) return;
	if (l >= L && r <= R) {
		tr[p] += v;
		tag[p] += v;
		return;
	}
	pushdown(p);
	modify(lson, l, mid, L, R, v);
	modify(rson, mid + 1, r, L, R, v);
	tr[p] = max(tr[lson], tr[rson]);
}
int query(int p, int l, int r, int L, int R) {
	if (l > R || r < L) return -inf;
	if (l >= L && r <= R) return tr[p];
	pushdown(p);
	return max(query(lson, l, mid, L, R), query(rson, mid + 1, r, L, R));
}

void solve() {
	cin >> n;
	build(1, 1, n);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	int res = 0;
	for (int i = 2; i < n; i++) {
		modify(1, 1, n, 1, i - 1, -1);
		modify(1, 1, n, i, n, 1);
		res = max(res, query(1, 1, n, 1, i - 1) + query(1, 1, n, i + 1, n) + a[i]);
	}
	cout << res << '\n';
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}