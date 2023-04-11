#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char ss[12][5] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct node {
    int h, r;
} a[2555];
int n, m, s, t;
ll cost[100005];
bool check(int y) { return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0); }
int input() {
    static char str[15];
    int d, y, h;
    scanf("%s %d %d %d", str, &d, &y, &h);
    int t = 0, tmp = 0;
    for (int i = 2000; i < y; i++) {
        if (check(i))
            t += 24 * 366;
        else
            t += 24 * 365;
    }
    if (check(y))
        day[1] = 29;
    else
        day[1] = 28;
    for (int i = 0; i < 12; i++) {
        if (strcmp(ss[i], str) == 0) break;
        tmp += day[i];
    }
    t = t + (tmp + d - 1) * 24 + h + 1;
    return t;
}

int ql, qr, q[100005];

void solve() {
    for (int i = 1; i <= n; i++) {
        a[i].h = input();
        scanf("%d", &a[i].r);
    }
    scanf("%d %d", &t, &s);
    for (int i = 1; i <= m; i++) scanf("%lld", &cost[i]);
    ll res = 0;
    ql = 0, qr = -1;
    int p = 1;
    for (int i = 1; i <= m; i++) {
        while (ql <= qr && i - q[ql] > t) ql++;
        while (ql <= qr && cost[q[qr]] + (i - q[qr]) * s >= cost[i]) qr--;
        q[++qr] = i;
        while (p <= n && a[p].h == i) {
            res += (cost[q[ql]] + (i - q[ql]) * s) * 1ll * a[p].r;
            ++p;
        }
    }
    printf("%lld\n", res);
}

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 && m == 0) break;
        solve();
    }
    return 0;
}