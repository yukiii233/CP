#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

ll a, b;

 ll exgcd(ll a, ll b, ll &x, ll &y) {
     if (b) {
         ll d = exgcd(b, a % b, y, x);
         return y -= a / b * x, d;
     } else return x = 1, y = 0, a;
 }
 ll gcd(ll a, ll b) {
     return b ? gcd(b, a % b) : a;
 }

void solve() {
    if (gcd(a, b) != 1) return puts("sorry"), void();
    ll x, y;
    exgcd(a, b, x, y);
    while (x < 0) x += b, y -= a;
    printf("%lld %lld\n", x, y);
    
}

int main() {
    while (~scanf("%lld %lld", &a, &b)) {
        solve();
    }
    return 0;
}