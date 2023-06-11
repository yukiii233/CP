#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
const int mod = 998244353;
const int N = 5e5 + 5;

int a[N], n;

struct Tree {
	#define lson (x << 1)
	#define rson ((x << 1) | 1)
	#define mid (l + r >> 1)
	int sum[N << 2], sumt[N << 2], mult[N << 2];

	void add(int x, int l, int r, int d) {
	    sumt[x] += d;
	    sumt[x] %= mod;
	    sum[x] += d * (r - l + 1) % mod;
	    sum[x] %= mod;
	}
	void mul(int x, int d) {
	    sumt[x] *= d;
	    sumt[x] %= mod;
	    mult[x] *= d;
	    mult[x] %= mod;
	    sum[x] *= d;
	    sum[x] %= mod;
	}
	void pushdown(int x, int l, int r) {
	    if (mult[x] != 1) {
	        mul(lson, mult[x]);
	        mul(rson, mult[x]);
	        mult[x] = 1;   
	    }
	    if (sumt[x] != 0) {
	        add(lson, l, mid, sumt[x]);
	        add(rson, mid + 1, r, sumt[x]);
	        sumt[x] = 0;
	    }
	}
	void pushup(int x) { sum[x] = sum[lson] + sum[rson]; }
	void build(int x, int l, int r) {
	    mult[x] = 1;
	    sumt[x] = 0;
	    if (l == r) {
	        sum[x] = 0;
	        return;
	    }
	    build(lson, l, mid);
	    build(rson, mid + 1, r);
	    pushup(x);
	    return;
	}
	void add_modify(int x, int l, int r, const int L, const int R, const int d) {
	    if (l > R || r < L) return;
	    if (l >= L && r <= R) {
	        add(x, l, r, d);
	        return;
	    }
	    pushdown(x, l ,r);
	    add_modify(lson, l, mid, L, R, d);
	    add_modify(rson, mid + 1, r, L, R, d);
	    pushup(x);
	    return;
	}
	void mul_modify(int x, int l, int r, const int L, const int R, const int d) {
	    if (l > R || r < L) return;
	    if (l >= L && r <= R) {
	        mul(x, d);
	        return;
	    }
	    pushdown(x, l, r);
	    mul_modify(lson, l, mid, L, R, d);
	    mul_modify(rson, mid + 1, r, L, R, d);
	    pushup(x);
	    return;
	}
	int query(int x, int l, int r, const int L, const int R) {
	    if (r < L || l > R) return 0;
	    if (l >= L && r <= R) return sum[x];
	    pushdown(x, l, r);
	    return (query(rson, mid + 1, r, L, R) + query(lson, l, mid, L, R)) % mod;
	}
} T[2];

void solve() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	T[0].build(1, 1, n + 1);
	T[1].build(1, 1, n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			T[0].mul_modify(1, 1, n + 1, 1, 1, 2);
			T[0].add_modify(1, 1, n + 1, 1, 1, 1);
			T[0].mul_modify(1, 1, n + 1, 2, n + 1, 2);
			T[0].add_modify(1, 1, n + 1, 2, 2, T[1].query(1, 1, n + 1, 2, 2));
			if (n > 1) T[1].mul_modify(1, 1, n + 1, 3, n + 1, 2);
		} else if (a[i] == 1) {
			T[0].mul_modify(1, 1, n + 1, 2, 2, 2);
			T[0].add_modify(1, 1, n + 1, 2, 2, T[0].query(1, 1, n + 1, 1, 1));
			
			if (n > 1) T[0].mul_modify(1, 1, n + 1, 3, n + 1, 2);
			if (n > 1) T[0].add_modify(1, 1, n + 1, 3, 3, T[1].query(1, 1, n + 1, 3, 3));
			if (n > 2) T[1].mul_modify(1, 1, n + 1, 4, n + 1, 2);
			
			T[1].mul_modify(1, 1, n + 1, 2, 2, 2);
			T[1].add_modify(1, 1, n + 1, 2, 2, 1);
		} else {
			T[0].mul_modify(1, 1, n + 1, a[i] + 1, n + 1, 2);
			T[0].add_modify(1, 1, n + 1, a[i] + 1, a[i] + 1, T[0].query(1, 1, n + 1, a[i] , a[i]));
			T[1].mul_modify(1, 1, n + 1, a[i] + 1, a[i] + 1, 2);
			T[1].add_modify(1, 1, n + 1, a[i] + 1, a[i] + 1, T[0].query(1, 1, n + 1, a[i] - 1, a[i] - 1));
			if (a[i] != n) T[0].add_modify(1, 1, n + 1, a[i] + 2, a[i] + 2, T[1].query(1, 1, n + 1, a[i] + 2, a[i] + 2));
			T[1].mul_modify(1, 1, n + 1, a[i] + 3, n + 1, 2);
		}
	}
	// for (int i = 0; i <= n; i++) {
	// 	printf("# %lld\n", i);
	// 	printf("%lld %lld\n", T[0].query(1, 1, n + 1, i + 1, i + 1), T[1].query(1, 1, n + 1, i + 1, i + 1));
	// }
	printf("%lld\n", (T[0].query(1, 1, n + 1, 1, n + 1) + T[1].query(1, 1, n + 1, 1, n + 1)) % mod);
}

signed main() {
	int T;
	scanf("%lld", &T);
	while (T--) {
		solve();
	}
	return 0;
}