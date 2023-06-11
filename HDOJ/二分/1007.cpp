#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, V;

void solve() {
    scanf("%d %d", &n, &V);
    vector<vector<int>> v(n + 1);
    vector<int> a;
    for (int i = 1; i <= n; i++) {
    	int num;
    	scanf("%d", &num);
    	while (num--) {
    		int x;
    		scanf("%d", &x);
    		v[i].push_back(x);
    		a.push_back(x);
    	}
    	sort(v[i].begin(), v[i].end());
    }
    sort(a.begin(), a.end());
    ll res = 0;
    for (int i = 1; i <= n; i++) {
    	for (int x : v[i]) {
    		int p = upper_bound(a.begin(), a.end(), V - x) - a.begin();
    		p = (int)a.size() - p;
    		int q = upper_bound(v[i].begin(), v[i].end(), V - x) - v[i].begin();
    		q = (int)v[i].size() - q;
    		res += p - q;
    	}
    }
    res /= 2;
    printf("%lld\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}