#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m;
map<int, vector<int>> mp;

void solve() {
    mp.clear();
    for (int i = 1; i <= n; i++) {
    	int x;
    	scanf("%d", &x);
    	mp[x].push_back(i);
    }
    for (auto &x : mp) reverse(x.second.begin(), x.second.end());
    for (int i = 1; i <= m; i++) {
    	int x;
    	scanf("%d", &x);
    	if (!mp.count(x) || mp[x].empty()) {
    		puts("-1");
    		continue;
    	}
    	int y = mp[x][(int)mp[x].size() - 1];
    	mp[x].pop_back();
    	printf("%d\n", y);
    }
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
        solve();
    }
    return 0;
}