#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1000 + 5;

void add(int x) {
	cout << "+ " << x << endl;
	int r;
	cin >> r;
}
int query(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	int res = 0;
	cin >> res;
	return res;
}

int p[N];
int p1[N], p2[N];

void solve() {
    int n;
    cin >> n;
    add(n + 1);
    add(n + 2);
    int l = 1, r = n, cnt = 0;
    while (l <= r) {
    	if (l == r) p[++cnt] = l++;
    	else p[++cnt] = l++, p[++cnt] = r--;
    }
    int rt = rand() % n + 1, mx = 0, wh;
    for (int i = 1; i <= n; i++) if (i != rt) {
    	int re;
    	if ((re = query(i, rt)) > mx) {
    		mx = re;
    		wh = i;
    	}
    }
    p1[wh] = p[1], p2[wh] = p[n];
    for (int i = 1; i <= n; i++) if (i != wh) {
    	int re = query(wh, i);
    	p1[i] = p[1 + re];
    	p2[i] = p[n - re]; 
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << p1[i] << ' ';
    for (int i = 1; i <= n; i++) cout << p2[i] << ' ';
    cout << endl;
	cin >> r;
}

int main() {
	srand(23333);
    int T;
	cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}