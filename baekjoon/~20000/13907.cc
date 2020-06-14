#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	int s, e;
	cin >> s >> e;
	vector<vector<pair<int, int>>> g(n + 1);
	for(int i =0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	priority_queue<tuple<int, int, int>> pq;
	vector<vector<int>> d(n + 1, vector<int>(n, 1e9));
	pq.emplace(0, s, 0);
	d[s][0] = 0;
	while(pq.size()) {
		auto [z, u, l] = pq.top(); pq.pop();
		if (-z != d[u][l] || l >= n - 1) continue;
		for(auto & [v, w] : g[u]) {
			int nz = -z + w;
			if (d[v][l + 1] > nz) {
				d[v][l + 1] = nz;
				pq.emplace(-nz, v, l + 1);
			}
		}
	}
	int pos = min_element(d[e].begin(), d[e].end()) - d[e].begin();
	cout << d[e][pos] << '\n';
	for(int i =0; i<k; ++i) {
		int p; cin >> p;
		d[e][pos] += pos * p;
		for(int i =0; i<pos; ++i) {
			d[e][i] += i * p;
			if (d[e][pos] > d[e][i]) pos = i;
		}
		cout << d[e][pos] << '\n';
	}
}