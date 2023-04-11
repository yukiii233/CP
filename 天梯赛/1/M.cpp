#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

string t;
struct node {
    string s[11];
} a[N];

vector<int> e[N];
unordered_map<string, int> id;
unordered_map<int, string> iid;
vector<string> res;
int dep[N];
int n, in[N];
int tot;

void update(string x) {
    if (!id.count(x)) {
        id[x] = ++tot;
        iid[tot] = x;
    }
}
bool check(int i, int j, int k) {
    for (int c = 1; c <= k; c++) if (a[i].s[c] != a[j].s[c]) return 0;
    return 1;
}
struct pii {
    string s;
    int x;
    bool operator < (const pii &p) const {
        return s > p.s;
    }
};

void solve() {
    cin >> n;
    id["#"] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        static string ss;
        vector<string> v;
        for (int i = 0; i < (int)(t.size()); i++) {
            ss.clear();
            int j = i;
            ss += t[i];
            while (j + 1 < (int)(t.size()) && t[j + 1] != '.') {
                j++;
                ss += t[j];
            }
            v.push_back(ss);
            i = j + 1;
           // cout << "***" << ' ' << ss << '\n';
        }
        int m = v.size();
        for (int j = 1; j <= 10 - m; j++) a[i].s[j] = "#";
        for (int j = 10 - m + 1; j <= 10; j++) a[i].s[j] = v[j + m - 11], update(a[i].s[j]);
    }
    for (int k = 1; k <= 10; k++) {
        for (int i = 1; i < n; i++) if (a[i].s[k] != a[i + 1].s[k] && a[i].s[k] != "#" && a[i + 1].s[k] != "#" && check(i, i + 1, k - 1)) {
            e[id[a[i].s[k]]].push_back(id[a[i + 1].s[k]]);
            in[id[a[i + 1].s[k]]]++;
        }
    }
    bool po = 0;
    priority_queue<pii> q;
    for (int i = 1; i <= tot; i++) if (!in[i]) q.push({iid[i], i});
    while (!q.empty()) {
        auto [s, u] = q.top();
        q.pop();
        if (po) cout << '.';
        else po = 1;
        cout << s;
        for (int v : e[u]) {
            in[v]--;
            if (in[v] == 0) q.push({iid[v], v});
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}