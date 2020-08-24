#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> rp(n + 1);
	for(int i =1; i<=n; ++i) cin >> rp[i];
	vector<vector<pair<int, int>>> g(n + 1);
	for(int i =1; i<n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	vector<array<int, 20>> p(n + 1), s(n + 1);
	function<void(int)> dfs = [&](int u) {
		for(auto & [v, w] : g[u]) {
			if (p[v][0]) continue;
			p[v][0] = u;
			s[v][0] = w;
			dfs(v);
		}
	};
	p[1][0] = 1;
	dfs(1);
	for(int j =1; j<20; ++j)
		for(int i =1; i<=n; ++i) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			s[i][j] = s[i][j - 1] + s[p[i][j - 1]][j - 1];
			if (s[i][j] > 100000) s[i][j] = 100001;
		}
	for(int i =1; i<=n; ++i) {
		int a = i;
		for(int j =19; ~j; --j) {
			if (rp[i] >= s[a][j]) {
				rp[i] -= s[a][j];
				a = p[a][j];
			}
		}
		cout << a << '\n';
	}
}