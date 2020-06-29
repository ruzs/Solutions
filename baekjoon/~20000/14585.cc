#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int g[301][301]{};
	for(int i =0; i<n; ++i) {
		int y, x;
		cin >> y >> x;
		g[y][x] = max(0, m - x - y);
	}
	int d[301][301];
	memset(d, -1, sizeof d);
	function<int(int, int)> dp = [&](int y, int x) {
		if (y >= 300 || x >= 300) return 0;
		int & ref = d[y][x];
		if (~ref) return ref;
		return ref = max(dp(y + 1, x), dp(y, x + 1)) + g[y][x];
	};
	cout << dp(0, 0);
}