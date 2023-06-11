#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

vector<ll> v;
int n, k;
ll a[N], sum[N];
int pos[N], mx[N << 2], dp[N];

#define lson (p << 1)
#define rson ((p << 1) | 1)
#define mid ((l + r) >> 1)
void build(int p, int l, int r) {
	mx[p] = -998244353;
	if (l == r) return;
	build(lson, l, mid);
	build(rson, mid + 1, r);
}
void insert(int p, int l, int r, int po, int va) {
	if (l == r) {
		mx[p] = max(mx[p], va);
		return;
	}
	if (po <= mid) insert(lson, l, mid, po, va);
	else insert(rson, mid + 1, r, po, va);
	mx[p] = max(mx[lson], mx[rson]);
}
int query(int p, int l, int r, int L, int R) {
	if (r < L || l > R) return -998244353;
	if (l >= L && r <= R) return mx[p];
	return max(query(lson, l, mid, L, R), query(rson, mid + 1, r, L, R));
}
#undef lson (p << 1)
#undef rson ((p << 1) | 1)
#undef mid ((l + r) >> 1)

bool check(ll mid) {
	build(1, 1, (int)(v.size()));
	fill(dp, dp + n + 1, -998244353);
	for (int i = 1; i <= n; i++) {
		ll x = sum[i] - mid;
		if (sum[i] <= mid) dp[i] = 1;
		int pp = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
		if (pp == (int)(v.size()) + 1) {
			insert(1, 1, (int)(v.size()), pos[i], dp[i]);
			continue;
		}
		dp[i] = max(dp[i], query(1, 1, (int)(v.size()), pp, (int)(v.size())) + 1);
		insert(1, 1, (int)(v.size()), pos[i], dp[i]);
	}
	return *max_element(dp, dp + n + 1) >= k;
}

void solve() {
	v.clear();
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
    	scanf("%lld", &a[i]);
    	sum[i] = sum[i - 1] + a[i];
    	v.push_back(sum[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++) {
    	int p = lower_bound(v.begin(), v.end(), sum[i]) - v.begin() + 1;
    	pos[i] = p;
    }
    ll l = -2e14, r = 1e9, ans = 233233;
    while (l <= r) {
    	ll mid = (l + r) >> 1;
    	if (check(mid)) r = mid - 1, ans = mid;
    	else l = mid + 1;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
         solve();
    }
    return 0;
}