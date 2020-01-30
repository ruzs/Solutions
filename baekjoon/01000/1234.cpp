#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

long long d[11][101][101][101];
long long fact(int a) {
	long long r = a;
	while(--a) r *= a;
	return r;
}
long long dp(int n, int a, int b, int c) {
	if (!n) return 1;
	auto & ref = d[n][a][b][c];
	if (ref != -1) return ref;
	ref = 0;
	int m, fn = fact(n), fm;
	if (n % 3 == 0) {
		m = n / 3;
		fm = fact(m);
		if (a >= m && b >= m && c >= m)
			ref += fn / fm / fm / fm * dp(n - 1, a - m, b - m, c - m);
	}
	if (n % 2 == 0) {
		m = n / 2;
		fm = fact(m);
		if (a >= m && b >= m) ref += fn / fm / fm * dp(n - 1, a - m, b - m, c);
		if (b >= m && c >= m) ref += fn / fm / fm * dp(n - 1, a, b - m, c - m);
		if (a >= m && c >= m) ref += fn / fm / fm * dp(n - 1, a - m, b, c - m);		
	}
	if (a >= n) ref += dp(n - 1, a - n, b, c);
	if (b >= n) ref += dp(n - 1, a, b - n, c);
	if (c >= n) ref += dp(n - 1, a, b, c - n);
	return ref;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(d, -1, sizeof d);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	cout << dp(n, a, b, c);
}
