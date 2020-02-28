#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for(int i=1; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<array<int, 2>> d(n + 1, {-1, -1});
	function<int(int, int, int)> dp = [&](int a, int c, int p = 0) {
		int & ref = d[a][c];
		if (~ref) return ref;
		ref = c;
		for(int b : g[a]) {
			if (b == p) continue;
			if (!c) ref += max(dp(b, 0, a), dp(b, 1, a));
			else ref += dp(b, 0, a);
		}
		return ref;
	};
	cout << max(dp(1, 0, 0), dp(1, 1, 0));
}