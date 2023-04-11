#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n, k, s;
bool vis[N];
struct node {
    int x, p;
} a[N];

void solve() {
    scanf("%d %d %d", &n, &k, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].x, &a[i].p);
    }
    sort(a + 1, a + n + 1, [](node x, node y) {
        return (x.x == y.x) ? x.p < y.p : x.x < y.x;
    });
    int res = 0, i;
    node last = {-1, -1};
    for (i = 1; i <= n && a[i].x < 175; i++);
    for (; i <= n; i++) {
        int cnt = 0;
        res++;
        last = a[i];
        while (i < n && a[i + 1].x == last.x) {
            i++;
            if (a[i].p >= s) res++;
            else cnt++;
        }
        res += min(cnt, k - 1);
    }
    printf("%d\n", res);
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}