#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int s, e, x, y;
	cin >> s >> e >> x >> y;
	int g[101][501]{};
	for(int i =0; i<m; ++i) {
		int a;
		cin >> a;
		g[a][i] = a + 1;
		g[a + 1][i] = a;
	}
	const int inf = 1e9;
	int d[101][501];
	memset(d, -1, sizeof d);
	function<int(int, int)> dp = [&](int a, int b) {
		if (a < 1 || a > n) return inf;
		if (b == m + 1) return a == e ? 0 : inf;
		int & ref = d[a][b];
		if (~ref) return ref;
		
		ref = inf;
		if (g[a][b]) {
			ref = min(ref, dp(g[a][b], b + 1));
			ref = min(ref, dp(a, b + 1) + x);
		} else {
			ref = dp(a, b + 1);
		}
		ref = min(ref, dp(a - 1, b) + y);
		ref = min(ref, dp(a + 1, b) + y);
		return ref;
	};
	cout << dp(s, 0);
}