#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int sex, H, W;
    cin >> sex >> H >> W;
    int sh, sw;
    sex == 0 ? (sh = 129, sw = 25) : (sh = 130, sw = 27);
    string t;
    if (H < sh) t = "duo chi yu!";
    else if (H > sh) t = "ni li hai!";
    else t = "wan mei!";
    cout << t << ' ';
    if (W < sw) t = "duo chi rou!";
    else if (W > sw) t = "shao chi rou!";
    else t = "wan mei!";
    cout << t << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}