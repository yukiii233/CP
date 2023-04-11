#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

char IO_BUF[N * 250];
char *buf = IO_BUF;

void read(ll &a) {
    for (a = 0; *buf < 48; buf++);
    while (*buf > 47)
        a = a * 10 + *buf++ - 48;
}
ll n, k;
ll s[N];
int q[N], ql, qr;

void solve() {
    k--;
    for (int i = 1; i <= n; i++) read(s[i]), s[i] += s[i - 1];
    q[ql = qr = 0] = 0;
    double res = 0.0;
    for (int i = k; i <= n; i++) {
        int pos;
        if (ql == qr) pos = q[ql];
        else {
            if ((s[i] - s[q[qr - 1]]) * (q[qr] - q[qr - 1])
            >= (s[q[qr]] - s[q[qr - 1]]) * (i - q[qr - 1])) pos = q[qr];
            else {
                int l = ql, r = qr - 1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if ((s[i] - s[q[mid]]) * (q[mid + 1] - q[mid])
                    > (s[q[mid + 1]] - s[q[mid]]) * (i - q[mid])) l = mid + 1;
                    else r = mid - 1, pos = q[mid];
                }
            }
        }
        //printf("%d %d %lf\n", i, pos, 1.0 * (s[i] - s[pos]) / (i - pos));
        res = max(res, 1.0 * (s[i] - s[pos]) / (i - pos));
        if (i - k < 1) continue;
        while (ql < qr && (s[i - k] - s[q[qr]]) * (q[qr] - q[qr - 1])
            <= (s[q[qr]] - s[q[qr - 1]]) * (i - k - q[qr])) qr--;
        q[++qr] = i - k;
    }
    printf("%.2lf\n", res);
}

int main() {
    int tol = fread(IO_BUF, 1, N * 250, stdin);
    while (buf - IO_BUF + 1 < tol) {
        read(n);
        read(k);
        solve();
    }
    return 0;
}