#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

void solve() {
    int a, b, c[3];
    scanf("%d %d %d %d", &a, &b, &c[1], &c[2]);
    if (c[1] >= c[2]) {
        if (c[2] < a) {
            if (c[1] >= b) {
                printf("%d-Y %d-Y\n", c[1], c[2]);
                puts("qing 1 zhao gu hao 2");
            } else {
                if (c[1] >= a) {
                    printf("%d-Y %d-N\n", c[1], c[2]);
                    puts("1: huan ying ru guan");
                } else {
                    printf("%d-N %d-N\n", c[1], c[2]);
                    puts("zhang da zai lai ba");
                }
            }
        } else {
            printf("%d-Y %d-Y\n", c[1], c[2]);
            puts("huan ying ru guan");
        }
    } else {
        if (c[1] < a) {
            if (c[2] >= b) {
                printf("%d-Y %d-Y\n", c[1], c[2]);
                puts("qing 2 zhao gu hao 1");
            } else {
                if (c[2] >= a) {
                    printf("%d-N %d-Y\n", c[1], c[2]);
                    puts("2: huan ying ru guan");
                } else {
                    printf("%d-N %d-N\n", c[1], c[2]);
                    puts("zhang da zai lai ba");
                }
            }
        } else {
            printf("%d-Y %d-Y\n", c[1], c[2]);
            puts("huan ying ru guan");
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