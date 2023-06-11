#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, z[N];
char s[N];

void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) s[i + n] = s[i];
    n += n;
    for (int i = 2, l = 0, r = 0; i <= n; i++) {
    	if (r >= i && r - i + 1 > z[i - l + 1]) {
    		z[i] = z[i - l + 1];
    	} else {
    		z[i] = max(0, r - i + 1);
    		while (z[i] < n - i + 1 && s[z[i] + 1] == s[i + z[i]]) ++z[i];
    	}
    	if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    int a[3] = {0, 0, 0};
    for (int i = 2; i <= n / 2 + 1; i++) {
    	if (z[i] >= n / 2) a[1]++;
    	else {
    		if (s[z[i] + 1] > s[i + z[i]]) a[0]++;
    		else a[2]++;
    	}
    }
    int step = 1;
    for (int i = 1; i <= n / 2; i++) if (i + z[i] - 1 == n) {
    	step = n / (i - 1) / 2;
    	break;
    }
    static int Case = 0;
    printf("Case %d: %d %d %d\n", ++Case, a[0] / step, a[1] / step, a[2] / step);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}