#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct fenwick {
	vector<T> a;
	fenwick(int n) { a.resize(n); }

	void add(int p, T x) {
		do a[p] += x;
		while ((p += p & -p) < a.size());
	}
	T sum(int p) {
		T r{};
		do r += a[p];
		while (p -= p & -p);
		return r;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c;
	cin >> n >> c;
	vector<vector<int>> g(n + 1);
	for(int i =1; i<n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ett = 0;
	vector<int> d(n + 1), tin(n + 1), tout(n + 1);
	function<void(int)> dfs = [&](int u) {
		tin[u] = ++ett;
		for(int v : g[u]) {
			if (!d[v]) {
				d[v] = d[u] + 1;
				dfs(v);
			}
		}
		tout[u] = ett;
	};
	d[c] = 1;
	dfs(c);

	fenwick<int> fw(n + 1);
	int q;
	cin >> q;
	while(q--) {
		int cmd, x;
		cin >> cmd >> x;
		if (cmd == 1) {
			fw.add(tin[x], 1);
		} else {
			cout << (long long)d[x] * (fw.sum(tout[x]) - fw.sum(tin[x] - 1)) << '\n';
		}
	}
}