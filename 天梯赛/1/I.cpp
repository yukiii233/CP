#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, m, k;
int a[N];
int stk[N], top, p;
vector<vector<int>> tree;

bool build() {
    vector<int> v;
    int last;
    if (top == 0 && p > n) return 0;
    if (top == 0) v.push_back(last = a[p++]);
    else v.push_back(last = stk[top--]);
    while (((top && stk[top] <= last) || p <= n) && (int)v.size() < k)  {
        if (top && stk[top] <= last) {
            v.push_back(last = stk[top--]);
        } else {
            if (p <= n && a[p] <= last) {
                v.push_back(last = a[p++]);
            } else if (top == m) {
                break;
            } else {
                stk[++top] = a[p++];
            }
        }
    }
    tree.push_back(v);
    return 1;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    p = 1;
    while (build());
    for (auto v : tree) {
        bool fl = 0;
        for (auto x : v) {
            if (fl) cout << ' ';
            else fl = 1;
            cout << x;
        }
        cout << '\n';
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}