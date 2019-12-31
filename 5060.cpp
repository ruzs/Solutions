#include <bits/stdc++.h>

using namespace std;

int t, n, m, c[201][201][201];
double a[201], d[201][201][201];
double dp(int l, int r, int h) {
	if (r - l + 1 == h) return 0;
	if (r - l + 1 < h || h < 2) return 1e9;
	double & ref = d[l][r][h];
	if (c[l][r][h]) return ref;
	c[l][r][h] = 1;
	if (h == 2) {
		ref = 0.0;
		for(int i =l + 1; i<r; ++i) {
			ref += fabs(a[l] + (a[r] - a[l]) * (i - l) / (r - l) - a[i]);
		}
		return ref;
	}
	ref = 1e9;
	for(int i =l + 1; i<r; ++i) {
		ref = min(ref, dp(l, i, 2) + dp(i, r, h - 1));
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		memset(c, 0, sizeof c);
		cin >> n >> m;
		for(int i =1; i<=n; ++i) cin >> a[i];
		cout << setprecision(20) << dp(1, n, m) / n << '\n';
	}
}
