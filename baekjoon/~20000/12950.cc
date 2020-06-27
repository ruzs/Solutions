#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<set<pair<int, char>>> g(n);
	for(int i =0; i<m; ++i) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		g[a].insert({b, c});
		g[b].insert({a, c});
	}
	int d[21][21];
	memset(d, -1, sizeof d);
	function<int(int, int)> dp = [&](int s, int e) {
		if (s == e) return 0;
		int & ref = d[s][e];
		if (~ref) return ref;

		ref = 1e9;
		for(auto [a, c] : g[s]) {
			if (a == e) ref = 1;
			for(auto [b, d] : g[e]) {
				if (c == d) ref = min(ref, dp(a, b) + 2);
			}
		}
		return ref;
	};
	int ans = dp(0, 1);
	if (ans < 1e9) cout << ans;
	else cout << -1;
}