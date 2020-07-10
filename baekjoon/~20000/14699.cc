#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> h(n);
	for(int & i : h) cin >> i;
	vector<vector<int>> g(n);
	while(m--) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> d(n, -1);
	function<int(int)> dp = [&](int u) {
		int & ref = d[u];
		if (~ref) return ref;
		ref = 1;
		for(int v : g[u]) {
			if (h[u] < h[v]) ref = max(ref, dp(v) + 1);
		}
		return ref;
	};
	for(int i =0; i<n; ++i) dp(i);
	for(int i =0; i<n; ++i) cout << d[i] << '\n';
}