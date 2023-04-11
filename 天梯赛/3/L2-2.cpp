#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n, m;
string fi[N], se[N];
map<string, int> r;
map<int, int> fz;

vector<int> G[N];
int dfc, dfn[N], rnk[N], siz[N], top[N], dep[N], son[N], faz[N], rtt;
void dfs1(int u, int fa) {
    fz[u] = rtt;
    dep[u] = dep[fa] + 1;
    siz[u] = 1;
    son[u] = -1;
    faz[u] = fa;
    for (int v : G[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[son[u]] < siz[v]) son[u] = v;
    }
}
void dfs2(int u, int fa, int tp) {
    dfn[u] = ++dfc;
    rnk[dfc] = u;
    top[u] = tp;
    if (son[u] != -1) dfs2(son[u], u, tp);
    for (int v : G[u]) {
        if (v == fa || v == son[u]) continue;
        dfs2(v, u, v);
    }
}
int LCA(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]])
            u = faz[top[u]];
        else
            v = faz[top[v]];
    }
    return dep[u] > dep[v] ? v : u;
}

int getsex(string s) {
    int len = s.size();
    if (s[len - 1] == 'm') return 1;
    if (s[len - 1] == 'f') return 0;
    if (s[len - 1] == 'n') return 1;
    return 0;
}
int getl(string s) {
    int len = s.size();
    if (s[len - 1] == 'm') return len - 1;
    if (s[len - 1] == 'f') return len - 1;
    if (s[len - 1] == 'n') return len - 4;
    return len - 7;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> fi[i] >> se[i];
        r[fi[i]] = i;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!r.count(se[i].substr(0, getl(se[i])))) q.push(i);
        else {
            G[r[se[i].substr(0, getl(se[i]))]].push_back(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        rtt = u;
        dfc = 0;
        dfs1(u, u);
        dfs2(u, u, u);
    }
    cin >> m;
    string a1, a2, b1, b2;
    while (m--) {
        cin >> a1 >> a2 >> b1 >> b2;
        if (!r.count(a1) || !r.count(b1)) {
            cout << "NA\n";
            continue;
        }
        if (getsex(se[r[a1]]) == getsex(se[r[b1]])) {
            cout << "Whatever\n";
            continue;
        } else {
            int u = r[a1], v = r[b1];
            if (fz[u] != fz[v]) cout << "Yes\n";
            else {
                int lca = LCA(u, v);
                if (dep[u] - dep[lca] < 4 || dep[v] - dep[lca] < 4) {
                    cout << "No\n";
                } else cout << "Yes\n";
            }
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