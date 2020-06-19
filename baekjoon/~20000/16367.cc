#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(2 * n), tg(2 * n);
	auto r = [n](int x) {
		return x < n ? x + n : x - n;
	};
	auto add = [&](int a, int b) {
		g[a].push_back(b);
		tg[b].push_back(a);
	};
	for(int i =0; i<m; ++i) {
		int a, b, c;
		char d, e, f;
		cin >> a >> d >> b >> e >> c >> f;
		a--; b--; c--;
		if (d == 'B') a += n;
		if (e == 'B') b += n;
		if (f == 'B') c += n;
		add(r(a), b);
		add(r(a), c);
		add(r(b), a);
		add(r(b), c);
		add(r(c), a);
		add(r(c), b);
	}
	vector<int> vis(n * 2), st, scc(n * 2);
	int c = 0;
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		for(int v : g[u]) if (!vis[v]) dfs(v);
		st.push_back(u);
	};
	for(int i =0; i<2*n; ++i)
		if (!vis[i]) dfs(i);

	dfs = [&](int u) {
		vis[u] = 0;
		scc[u] = c;
		for(int v : tg[u]) if (vis[v]) dfs(v);
	};
	for(int i =st.size() -1; i>=0; --i)
		if (vis[st[i]]) c++, dfs(st[i]);

	string ans = "";
	for(int i =0; i<n; ++i) {
		if (scc[i] == scc[r(i)]) {
			cout << -1;
			return 0;
		}
		if (scc[i] > scc[r(i)]) ans += 'R';
		else ans += 'B';
	}
	cout << ans;
}