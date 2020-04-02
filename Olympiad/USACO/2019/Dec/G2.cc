#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i =1; i<=n; ++i) cin >> a[i];
	vector<vector<int>> g(n + 1);
	for(int i =1; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<vector<tuple<int, int, int>>> q(n + 1);
	for(int i =0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		q[a].emplace_back(b, c, i);
		q[b].emplace_back(a, c, i);
	}
	function<void(int, int)> dfs;
	vector<pair<int, int>> rng(n + 1);
	int c = 0;
	dfs = [&](int v, int p) {
		rng[v].first = c++;
		for(int u : g[v]) if (u ^ p) dfs(u, v);
		rng[v].second = c - 1;
	};
	dfs(1, 0);
	string ans(m, '0');
	vector<vector<pair<int, int>>> chk(n + 1);
	vector<int> ord;
	auto anc = [rng](int a, int b) {
		return rng[a].first <= rng[b].first && rng[b].second <= rng[a].second;
	};
	dfs = [&](int v, int p) {
		chk[a[v]].emplace_back(v, ord.size());
		ord.push_back(v);
		for(auto & [u, c, idx] : q[v]) {
			if (chk[c].size()) {
				if (chk[c].back().first == v) ans[idx] = '1';
				else {
					int x = ord[chk[c].back().second + 1];
					if (!anc(x, u)) ans[idx] = '1';
				}
			}
		}
		for(int u : g[v]) {
			if (u ^ p) dfs(u, v);
		}
		chk[a[v]].pop_back();
		ord.pop_back();
	};
	dfs(1, 0);
	cout << ans;
}