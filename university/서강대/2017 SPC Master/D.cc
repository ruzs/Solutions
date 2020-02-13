#include <bits/stdc++.h>

using namespace std;

bool v[101];
auto dijkstra(int src, int n, vector<pair<int, int>> g[]) {
	vector<int> d(n + 1, 1e9);
	priority_queue<pair<int, int>> pq;

	pq.push({0, src});
	d[src] = 0;
	while(pq.size()) {
		auto [c, a] = pq.top(); pq.pop();
		if (d[a] < -c) continue;
		for(auto& [b, w] : g[a]) {
			int nc = -c + w;
			if (d[b] > nc) {
				d[b] = nc;
				pq.push({ -nc, b });
			}
		}
	}
	return d;
}
int main() {
	int n, m, k, t[101];
	vector<pair<int, int>> g[101];
	cin >> n >> m >> k;
	for(int i =1; i<=n; ++i) cin >> t[i];
	for(int i =0; i<k; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	int ans = 0;
	for(int i =1; i<=n; ++i) {
		auto d = dijkstra(i, n, g);
		int cnt = 0;
		for(int i =1; i<=n; ++i) if (d[i] <= m) cnt += t[i];
		ans = max(ans, cnt);
	}
	cout << ans;
}