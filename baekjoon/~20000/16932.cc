#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	vector<pair<int, int>> a, b;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			cin >> g[i][j];
			if (g[i][j]) a.push_back({i, j});
			else b.push_back({i, j});
		}
	}
	const int dy[] = {1, 0, -1, 0};
	const int dx[] = {0, -1, 0, 1};
	auto valid = [&](int y, int x) {
		return y >= 0 && x >= 0 && y < n && x < m;
	};
	int c = 2;
	vector<int> area(2);
	function<int(int, int)> dfs = [&](int y, int x) {
		g[y][x] = c;
		int r = 1;
		for(int w =0; w<4; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (valid(ny, nx) && g[ny][nx] == 1) r += dfs(ny, nx);
		}
		return r;
	};
	for(auto &[y, x] : a) {
		if (g[y][x] == 1)
			area.push_back(dfs(y, x)), c++;
	}
	int ans = 0;
	for(auto &[y, x] : b) {
		set<int> gr;
		int sum = 1;
		for(int w =0; w<4; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (valid(ny, nx) && g[ny][nx] && !gr.count(g[ny][nx])) {
				gr.insert(g[ny][nx]);
				sum += area[g[ny][nx]];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans;
}