#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

int n;
vector<int> G[N];
int in[N];
bool vis[N];
int ans, id;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++) {
            int x;
            cin >> x;
            G[i].push_back(x);
            in[x]++;
        }
    }
    int root;
    for (int i = 1; i <= n; i++) if (in[i] == 0) {
        root = i;
        break;
    }
    queue<pair<int , int> > q;
    q.push({root, 0});
    vis[root] = 1;
    while (!q.empty()) {
        auto [u, dep] = q.front();
        q.pop();
        if (dep > ans) {
            ans = dep;
            id = u;
        }
        for (int v : G[u]) {
            if (!vis[v]) q.push({v, dep + 1}), vis[v] = 1;
        }
    }
    cout << id << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}