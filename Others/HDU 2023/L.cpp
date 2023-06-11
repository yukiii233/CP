#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 5;

int n, m;
char s[N], s1[N], t[N], tmp[N + N];
int k1[N], k2[N], k3[N], sum1[N], sum2[N];
bool vis[N];
vector<int> lis, G[N];

int tr[N];
int lowbit(int x) {
    return x & -x;
}
void add(int x, int d) {
    for (int i = x; i <= m + 1; i += lowbit(i)) tr[i] += d;
}
int qry(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
int qry(int l, int r) {
    return qry(r) - qry(l - 1);
}

int dfc, dfn[N], rnk[N], siz[N], top[N], dep[N], son[N], faz[N];
void dfs1(int u, int fa) {
    dep[u] = dep[fa] + 1;
    siz[u] = 1;
    son[u] = -1;
    faz[u] = fa;
    vis[u] = 1;
    for (int v : G[u]) if (!vis[v]) {
        if (v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[son[u]] < siz[v]) son[u] = v;
    }
}
void dfs2(int u, int fa, int tp) {
    if (vis[u]) return;
    vis[u] = 1;
    dfn[u] = ++dfc;
    rnk[dfc] = u;
    top[u] = tp;
    if (son[u] != -1) dfs2(son[u], u, tp);
    for (int v : G[u]) {
        if (v == fa || v == son[u]) continue;
        dfs2(v, u, v);
    }
}
int query(int u, int v) {
    int res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            res += qry(dfn[top[u]], dfn[u]);
            u = faz[top[u]];
        } else {
            res += qry(dfn[top[v]], dfn[v]);
            v = faz[top[v]];
        }
    }
    //printf("** %d %d\n", dfn[u], dfn[v]);
    if (dep[u] < dep[v]) res += qry(dfn[u], dfn[v]);
    else res += qry(dfn[v], dfn[u]);
    return res;
}
char ch[15];
void print( int k ) {
    if (k == 0) {putchar('0');
        putchar('\n');
        return;}
    int num = 0;
    while ( k > 0 ) ch[++num] = k % 10, k /= 10;
    while ( num )
        putchar( ch[num--] + 48 );
    putchar( 32 );
    putchar('\n');
}

void solve() {
    scanf("%d %d %s %s", &n, &m, s + 1, t + 1);
    for (int i = 1; i <= n; i++) s1[i] = s[n - i + 1];
    for (int i = 0; i <= m + 1; i++) G[i].clear(), tr[i] = 0, vis[i] = 0;
    dfc = 0;
    int len = 0;
    for (int i = 1; i <= m; i++) tmp[++len] = t[i];
    tmp[++len] = '#';
    for (int i = 1; i <= n; i++) tmp[++len] = s1[i];
    for (int i = 2; i <= len; i++) {
        int j = k1[i - 1];
        while (j != 0 && tmp[i] != tmp[j + 1]) j = k1[j];
        if (tmp[i] == tmp[j + 1]) k1[i] = j + 1;
        else k1[i] = 0;
    }
    len = m + 1;
    for (int i = 1; i <= n; i++) tmp[++len] = s[i];
    for (int i = 2; i <= len; i++) {
        int j = k2[i - 1];
        while (j != 0 && tmp[i] != tmp[j + 1]) j = k2[j];
        if (tmp[i] == tmp[j + 1]) k2[i] = j + 1;
        else k2[i] = 0;
    }
    len = 0;
    for (int i = 1; i <= n; i++) tmp[++len] = s1[i];
    tmp[++len] = '#';
    for (int i = 1; i <= m; i++) tmp[++len] = t[i];
    for (int i = 2; i <= len; i++) {
        int j = k3[i - 1];
        while (j != 0 && tmp[i] != tmp[j + 1]) j = k3[j];
        if (tmp[i] == tmp[j + 1]) k3[i] = j + 1;
        else k3[i] = 0;
    }
    lis.clear();
    int u = k3[n + m + 1];
    while (u) {
        if (u != m) lis.push_back(m - u);
        u = k3[u];
    }
    sort(lis.begin(), lis.end(), greater<int>());
    for (int i = m + 2; i <= n + m + 1; i++) {
        sum1[i - m - 1] = sum1[i - m - 2] + (k1[i] == m);
    }
    for (int i = m + 2; i <= n + m + 1; i++) {
        sum2[i - m - 1] = sum2[i - m - 2] + (k2[i] == m);
    }
    for (int i = m + 2; i <= n + m + 1; i++) if (k2[i] != 0) {
            G[k2[k2[i]]].push_back(k2[i]);
            //printf("po : %d %d\n", k2[i], k2[k2[i]]);
        }
    dfs1(0, 0);
    fill(vis, vis + m + 2, 0);
    dfs2(0, 0, 0);
    for (int x : lis) add(dfn[x], 1);
    printf("%d\n", sum1[n]);
    for (int k = 2; k < n; k++) {
        int res = sum2[k - 1] + sum1[n - k + 1];
        while (!lis.empty() && m - lis.back() > n - k + 1) {
            add(dfn[lis.back()], -1);
            lis.pop_back();
        }
        res += query(0, k2[m + k]);
        // for (int x : lis) {
        //     bool f = 0;
        //     u = k2[m + k];
        //     while (u) {
        //         if (u == x) f = 1;
        //         u = k2[u];
        //     }
        //     res += f;
        // }
        printf("%d\n", res);
    }
    printf("%d\n", sum2[n]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}