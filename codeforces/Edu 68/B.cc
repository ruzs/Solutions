#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<int> r(n), c(m);
	for(auto & i : a) cin >> i;

	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			if (a[i][j] == '*') r[i]++, c[j]++;
		}
	}
	
	int ans = 1e9;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			ans = min(ans, n - r[i] + m - c[j] - (a[i][j] == '.'));
		}
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}