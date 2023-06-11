#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    map<string, int> mp;
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    string rt;
    for (int i = 1; i <= n; i++) {
    	string s;
    	cin >> s;
    	if (i == 1) rt = s;
    	mp[s]++;
    }
    cnt = mp[rt];
    cout << cnt << '\n';
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}