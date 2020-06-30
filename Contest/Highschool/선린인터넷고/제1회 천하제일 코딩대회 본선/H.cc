#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1);
	for(int i =1; i<n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	struct T {
		int x, l, i;
		bool operator < (const T & b) const {
			return x < b.x || x == b.x && l > b.l;
		}
	};
	function<T(int, int)> dfs = [&](int u, int p) {
		T mx = {0, 0, u};
		for(auto & [v, w] : g[u]) {
			if (v == p) continue;
			T tmp = dfs(v, u);
			tmp.l += w;
			tmp.x += 1;
			mx = max(mx, tmp);
		}
		return mx;
	};
	cout << (dfs(dfs(1, 0).i, 0).l + m - 1) / m;
}