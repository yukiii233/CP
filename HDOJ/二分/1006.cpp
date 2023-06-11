#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 5e5 + 5;

int n, m;
int a[N];

bool check(int x) {
	int res = 0;
	for (int i = 1; i <= n; i++) 
		res += (a[i] + x - 1) / x;
	return res <= m;
}

void solve() {
    for (int i = 1; i <= n; i++)
    	scanf("%d", &a[i]);
   	int l = 0, r = *max_element(a + 1, a + n + 1), ans = -1;
   	while (l <= r) {
   		int mid = (l + r) >> 1;
   		if (check(mid)) r = mid - 1, ans = mid;
   		else l = mid + 1;
   	}
   	printf("%d\n", ans);
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
    	if (n == -1 && m == -1) break;
        solve();
    }
    return 0;
}