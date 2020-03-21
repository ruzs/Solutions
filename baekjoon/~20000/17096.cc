#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1);
	for(int i =0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	priority_queue<pair<long long, int>> pq;
	vector<long long> d(n + 1, 1e18);
	pq.push({0, 1});
	d[1] = 0;
	while(pq.size()) {
		auto [c, a] = pq.top(); pq.pop();
		if (d[a] < -c) continue;
		for(auto& [b, w] : g[a]) {
			long long nc = -c + w;
			if (d[b] > nc) {
				d[b] = nc;
				pq.push({-nc, b});
			}
		}
	}
	long long ans = 0;
	bitset<500001> v;
	function<void(int)> dfs = [&](int a) {
		if (v[a]) return;
		v[a] = 1;
		int mnw = 1e9, mnb = -1;
		for(auto& [b, w] : g[a]) {
			if (d[b] + w == d[a] && mnw > w) {
				mnw = w;
				mnb = b;
			}
		}
		if (mnw < 1e9) {
			ans += mnw;
			dfs(mnb);
		}
	};
	for(int i =2; i<=n; ++i) dfs(i);
	cout << ans;
}