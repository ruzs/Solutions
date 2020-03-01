#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i =0; i<n; ++i) cin >> a[i];
	for(int i =0; i<m; ++i) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a.size() < b.size()) swap(a, b), swap(n, m);
	vector<vector<int>> d(n, vector<int>(m, -1));
	auto dp = [&](auto& dp, int x, int y) {
		if (y == m) return 0;
		if (x == n) return (int)1e9;
		int & ref = d[x][y];
		if (~ref) return ref;
		ref = min(dp(dp, x + 1, y), dp(dp, x + 1, y + 1) + abs(a[x] - b[y]));
		return ref;
	};
	cout << dp(dp, 0, 0);
}