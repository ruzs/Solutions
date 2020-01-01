#include <bits/stdc++.h>

using namespace std;
int t, n, m, a[101], b[101], d[101][101];

int dp(int ai, int bi) {
	int & ref = d[ai][bi];
	if (ref != -1) return ref;

	ref = 2;
	long long x = ai ? bi ? a[ai] > b[bi] ? a[ai] : b[bi] : a[ai] : bi ? b[bi] : -1e10;
	for(int i =ai + 1; i<=n; ++i) {
		if (x < a[i]) ref = max(ref, dp(i, bi) + 1);
	}
	for(int i =bi + 1; i<=m; ++i) {
		if (x < b[i]) ref = max(ref, dp(ai, i) + 1);
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i =1; i<=n; ++i) cin >> a[i];
		for(int i =1; i<=m; ++i) cin >> b[i];
		memset(d, -1, sizeof d);
		cout << dp(0, 0) - 2 << '\n';
	}
}
