#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	pair<int, int> ans = {1e9, 0};
	for(int src =1; src<=n; ++src) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> d(n + 1, 1e9);
		pq.push({0, src});
		d[src] = 0;
		while (pq.size()) {
			auto [c, u] = pq.top();
			pq.pop();
			if (d[u] < c) continue;
			d[u] = c;
			for (auto & [v, w] : g[u]) {
				if (d[v] > c + w) {
					d[v] = c + w;
					pq.push({d[v], v});
				}
			}
		}
		pair<int, int> time = {0, 0};
		for(int u = 1; u<=n; ++u) for(auto & [v, w] : g[u]) {
			int x = d[v] + d[u] + w;
			time = max(time, {x / 2, x % 2 ? 5 : 0});
		}
		ans = min(ans, time);
	}
	cout << ans.first << '.' << ans.second;
}