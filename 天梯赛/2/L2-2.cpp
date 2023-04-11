#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e3 + 5;

int n, p;
map<string, int> mp;
map<string, bool> pd;

struct node {
    string name, id, he, ti;
    int t;
    bool operator < (const node &q) const {
        return ti == q.ti ? t < q.t : ti < q.ti;
    }
} a[N];

void solve() {
    cin >> n >> p;
    vector<pair<int, pair<string, string>>> ill;
    int tim = 0;
    for (int z = 1; z <= n; z++) {
        int T, S;
        cin >> T >> S;
        for (int i = 1; i <= T; i++) {
            cin >> a[i].name >> a[i].id >> a[i].he >> a[i].ti;
            a[i].t = i;
        }
        sort(a + 1, a + T + 1);
        //printf("# %d\n", z);
        for (int i = 1; i <= T; i++) {
            ++tim;
            if (a[i].id.size() != 18) continue;
            if (S != 0 && (!mp.count(a[i].id) || mp[a[i].id] + p + 1 <= z)) {
                S--;
                cout << a[i].name << ' ' << a[i].id << '\n';
                mp[a[i].id] = z;
            }
            if (a[i].he == "1") ill.push_back({tim, {a[i].name, a[i].id}});
        }
    }
    sort(ill.begin(), ill.end());
    for (auto zz : ill) {
        auto x = zz.second.first;
        auto y = zz.second.second;
        if (!pd.count(y)) {
        cout << x << ' ' << y << '\n';
        pd[y] = 1;
    }
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}