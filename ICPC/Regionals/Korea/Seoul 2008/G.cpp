#include <bits/stdc++.h>
using namespace std;

int n, a[10];
char s[60], t[10][10];
bool chk(int i) {
	int ps = 0;
	for(int j =i; ~j; --j) {
		ps += a[j];
		if (t[j][i] == '0' && ps != 0) return 0;
		if (t[j][i] == '+' && ps <= 0) return 0;
		if (t[j][i] == '-' && ps >= 0) return 0;
	}
	return 1;
}
bool rec(int i) {
	if (i == n) {
		for(int j =0; j<n; ++j) cout << a[j] << ' ';
		return 1;
	}
	if (t[i][i] == '-') {
		for(int j =-10; j<0; ++j) {
			a[i] = j;
			if (chk(i) && rec(i + 1)) return 1;
		}
	}
	else if (t[i][i] == '+') {
		for(int j =1; j<=10; ++j) {
			a[i] = j;
			if (chk(i) && rec(i + 1)) return 1;
		}
	}
	else {
		a[i] = 0;
		if (rec(i + 1)) return 1;
	}
	return 0;
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	for(int i =0, k =0; i<n; ++i) {
		for(int j =i; j<n; ++j) {
			t[i][j] = s[k++];
		}
	}
	rec(0);
}
