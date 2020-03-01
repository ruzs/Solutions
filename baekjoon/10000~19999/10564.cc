#include <bits/stdc++.h>

using namespace std;

int n, m, a[10], d[5001][10];
int dp(int x, int y) {
	if (x > n) return -1e9;
	if (x == n) return 0;
	int & ref = d[x][y];
	if (ref != -1) return ref;
	ref = -1e9;
	for(int i =0; i<m; ++i) {
		ref = max(ref, dp(x + (x - a[i]) / 2, y + a[i]) + a[i]);
	}
	return ref;
}
void solve() {
	memset(d, -1, sizeof d);
	cin >> n >> m;
	for(int i =0; i<m; ++i) cin >> a[i];
	int ans = dp(0, 0);
	if (ans > 0) cout << ans << '\n';
	else cout << "-1\n";
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}