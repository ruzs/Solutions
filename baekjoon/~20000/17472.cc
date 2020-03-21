#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			cin >> g[i][j];
		}
	}
	constexpr int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	constexpr int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [=](int y, int x) {
		return y >= 0 && x >= 0 && y < n && x < m;
	};
	function<void(int, int, int)> dfs = [&](int y, int x, int c) {
		g[y][x] = c;
		for(int w =0; w<4; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (valid(ny, nx) && g[ny][nx] == 1) dfs(ny, nx, c);
		}
	};
	int component = 2;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			if (g[i][j] == 1) dfs(i, j, component++);
		}
	}
	vector<tuple<int, int, int>> e;
	for(int i =0; i<n; ++i) {
		int l = -1;
		for(int j =1; j<m; ++j) {
			if (g[i][j] && !g[i][j - 1]) {
				if (~l && j - l >= 2) e.push_back({j - l, g[i][j], g[i][l - 1]});
			} else if (!g[i][j] && g[i][j - 1]) l = j;
		}
	}
	for(int j =0; j<m; ++j) {
		int l = -1;
		for(int i =1; i<n; ++i) {
			if (g[i][j] && !g[i - 1][j]) {
				if (~l && i - l >= 2) e.push_back({i - l, g[i][j], g[l - 1][j]});
			} else if (!g[i][j] && g[i - 1][j]) l = i;
		}
	}
	sort(e.begin(), e.end());
	struct disjoint_set {
		vector<int> a;
		disjoint_set(int n) { a.resize(n, -1); }
	
		int find(int u) {
			return a[u] < 0 ? u : a[u] = find(a[u]);
		}
		int size(int u) {
			return -a[find(u)];
		}
		int merge(int u, int v) {
			u = find(u); v = find(v);
			return u == v ? -1 : (a[u] += a[v], a[v] = u);
		}
	} ds(component);
	int ans = 0;
	for(auto & [c, a, b] : e) {
		if (~ds.merge(a, b)) ans += c;
	}
	for(int i =3; i<component; ++i) {
		if (ds.find(i) != ds.find(i - 1)) ans = -1;
	}
	if (ans < 2) ans = -1;
	cout << ans;
}