#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m, s[N], t[N * 2], d[N * 2];

int mx[N * 9];
#define lson (p << 1)
#define rson ((p << 1) | 1)
#define mid ((l + r) >> 1)
void build(int p, int l, int r) {
	mx[p] = 0;
	if (l == r) {
		mx[p] = d[l * 2 - 1] / 2 - l + 1;
		return;
	}
	build(lson, l, mid);
	build(rson, mid + 1, r);
	mx[p] = max(mx[lson], mx[rson]);
}
int query(int p, int l, int r, int L, int R, int v) {
	if (l > R || r < L) return -1;
	if (l == r) return mx[p] >= v ? l : -1;
	if (l >= L && r <= R && mx[p] < v) return -1;
	int res = query(rson, mid + 1, r, L, R, v);
	if (res != -1) return res;
	return query(lson, l, mid, L, R, v);
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    	scanf("%d", &s[i]);
    m = n * 2 + 1;
    for (int i = 1; i <= n; i++)
    	t[i * 2] = s[i], t[i * 2 - 1] = -1;
   	for (int i = 1, l = 0, r = 0; i <= m; i++) {
   		int k = i <= r ? min(d[r - i + l], r - i + 1) : 1;
   		while (i + k <= m && i - k >= 1 && t[i + k] == t[i - k]) k++;
   		d[i] = k--;
   		if (i + k > r) r = i + k, l = i - k;
   	}
   	int res = 0, v = 0;
   	build(1, 1, n);
   	for (int i = 2; i < n; i++) {
   		v--;
   		int re = query(1, 1, n, i + 1, i + d[i * 2 - 1] / 2, v);
   		res = max(res, re - i);
   	}
   	static int Case = 0;
   	printf("Case #%d: %d\n", ++Case, res * 3);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}