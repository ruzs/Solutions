#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(auto & i : g) cin >> i;
	constexpr int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	constexpr int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [n, m](int y, int x)
		{ return y >= 0 && x >= 0 && y < n && x < m; };
	auto bfs = [&](int y, int x) {
		queue<pair<int, int>> q;
		pair<int, int> ret{};
		if (g[y][x] == 'o') ret.first++;
		else if (g[y][x] == 'v') ret.second++;
		q.push({y, x});
		g[y][x] = '#';
		while(q.size()) {
			auto [y, x] = q.front(); q.pop();
			for(int w = 0; w<4; ++w) {
				int ny = y + dy[w], nx = x + dx[w];
				if (valid(ny, nx) && g[ny][nx] != '#') {
					if (g[ny][nx] == 'o') ret.first++;
					else if (g[ny][nx] == 'v') ret.second++;
					g[ny][nx] = '#';
					q.push({ny, nx});
				}
			}
		}
		return ret;
	};
	int sheep = 0, wolf = 0;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			if (g[i][j] != '#') {
				auto r = bfs(i, j);
				if (r.first > r.second) sheep += r.first;
				else wolf += r.second;
			}
		}
	}
	cout << sheep << ' ' << wolf;
}