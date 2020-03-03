#include <bits/stdc++.h>

using namespace std;

struct disjoint_set {
	vector<int> a;
	disjoint_set(int n) {
		a.assign(n, -1);
	}
	int find(int u) {
		return a[u] < 0 ? u : a[u] = find(a[u]);
	}
	int size(int u) {
		return -a[find(u)];
	}
	int merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u != v) {
			a[u] += a[v];
			a[v] = u;
		}
		return u;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	disjoint_set ds(n * n);
	vector<vector<int>> g(n, vector<int>(n));
	auto enc = [n](int r, int c) { return r * n + c; };
	auto num = [&](int x) { return g[x / n][x % n]; };
	for(int i =0; i<n; ++i) {
		for(int j =0; j<n; ++j) {
			cin >> g[i][j];
			if (i && g[i - 1][j] == g[i][j]) ds.merge(enc(i - 1, j), enc(i, j));
			if (j && g[i][j - 1] == g[i][j]) ds.merge(enc(i, j - 1), enc(i, j));
		}
	}
	int ans = 0;
	struct component { map<int, int> cn, cs; };
	map<pair<int, int>, component> cg;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<n; ++j) {
			ans = max(ans, ds.size(enc(i, j)));
			auto add_edge = [&](int u, int v) {
				int a = ds.find(enc(i, j));
				int b = ds.find(enc(u, v));
				auto& c = cg[minmax(g[i][j], g[u][v])];
				function<int(int)> find = [&](int x) {
					if (c.cn[x] == x) return x;
					return c.cn[x] = find(c.cn[x]);
				};
				if (!c.cn.count(a)) c.cn[a] = a, c.cs[a] = ds.size(a);
				if (!c.cn.count(b)) c.cn[b] = b, c.cs[b] = ds.size(b);
				if (find(a) == find(b)) return;
				c.cs[find(a)] += c.cs[find(b)];
				c.cn[find(b)] = find(a);
			};
			if (i && g[i - 1][j] != g[i][j]) add_edge(i - 1, j);
			if (j && g[i][j - 1] != g[i][j]) add_edge(i, j - 1);
		}
	}
	cout << ans << '\n';
	for(auto & [tmp, c] : cg) {
		for(auto i : c.cs) ans = max(ans, i.second);
	}
	cout << ans;
}