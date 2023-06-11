#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 5;

string s[8];
int a[30];

void print(int a, int b, int c, int d, int e, char x) {
	if (a ==5 && b ==2 && c ==2  && d ==2 && e ==5 ) printf("0");
	if (a ==0 && b ==0 && c ==0  && d ==0&& e == 5) printf("1");
	if (a ==4 && b ==3 && c ==3  && d ==3 && e ==4 && x == '.') printf("2");
	if (a ==3 && b ==3 && c ==3  && d ==3 && e == 5) printf("3");
	if (a == 3&& b ==1 && c == 1 && d ==1 && e ==5 ) printf("4");
	if (a == 4&& b ==3 && c ==3  && d ==3 && e == 4 && x != '.') printf("5");
	if (a ==5 && b ==3 && c ==3  && d ==3 && e ==4 ) printf("6");
	if (a ==1 && b ==1 && c == 1 && d ==1 && e ==5 ) printf("7");
	if (a == 5&& b ==3&& c ==3  && d == 3&& e ==5 ) printf("8");
	if (a ==4 && b ==3 && c ==3  && d ==3 && e == 5) printf("9");
}

void solve() {
	for (int i = 1; i <= 5; i++) 
		getline(cin, s[i]);
	for (int i = 1; i <= 18; i++) {
		for (int j = 1; j <= 5; j++) {
			a[i] += s[j][i - 1] == '*';
		}
	}
	print(a[1], a[2], a[3], a[4], a[5], s[2][0]);
	print(a[7], a[8], a[9], a[10], a[11], s[2][6]);
	print(a[13], a[14], a[15], a[16], a[17], s[2][12]);
	puts("");
}

int main() {
	solve();
	return 0;
}