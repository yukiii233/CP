#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int query(int x) {
	int res;
	cout << "? " << x << endl;
	cin >> res;
	return res;
}

void solve() {
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l + 1 < r) {
    	int mid = (l + r) >> 1;
    	if (query(mid) == 1) r = mid;
    	else l = mid;
    }
    cout << "! " << l << endl;
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}