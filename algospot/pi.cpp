#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int t, d[N], alen;
char a[N];
int score(char *a, int n) {
	int f = 1;
	for(int i =0; i<n; ++i) if (a[i] != a[0]) {
		f = 0;
		break;
	} if (f) return 1;
	f = 1;
	for(int i =1; i<n; ++i) if (a[i] - a[i - 1] != a[1] - a[0]) {
		f = 0;
		break;
	} if (abs(a[1] - a[0]) == 1 && f) return 2;
	f = 1;
	for(int i =2; i<n; ++i) if (a[i] != a[i - 2]) {
		f = 0;
		break;
	} if (f) return 4;
	f = 1;
	for(int i =1; i<n; ++i) if (a[i] - a[i - 1] != a[1] - a[0]) {
		f = 0;
		break;
	} if (f) return 5;
	return 10;
}
int dp(int x) {
	if (x > alen) return 1e9;
	if (x == alen) return 0;
	int & ref = d[x];
	if (ref != -1) return ref;

	ref = 1e9;
	for(int i =3; i<=5; ++i) {
		ref = min(ref, score(a + x, i) + dp(x + i));
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> a;
		alen = strlen(a);
		memset(d, -1, sizeof d);
		cout << dp(0) << '\n';
	}
}
