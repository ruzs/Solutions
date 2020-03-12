#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		pair<int, int> a{}, b;
		vector<string> g(n + 2);
		g[0].resize(m + 2, '.');
		for(int i =1; i<=n; ++i) {
			cin >> g[i];
			g[i] = "." + g[i] + ".";
			for(int j =1; j<=m; ++j) {
				if (g[i][j] == '$') {
					if (a.first) b = {i, j};
					else a = {i, j};
				}
			}
		}
		g[n + 1].resize(m + 2, '.');
		const int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
		const int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
		auto valid = [&](int y, int x) {
			return y >= 0 && x >= 0 && y < n + 2 && x < m + 2;
		};
		auto bfs = [&](pair<int, int> src) {
			deque<pair<int, int>> q = {src};
			vector<vector<int>> d(n + 2, vector<int>(m + 2, 1e9));
			d[src.first][src.second] = 0;
			while(q.size()) {
				auto [y, x] = q.front(); q.pop_front();
				for(int w = 0; w<4; ++w) {
					int ny = y + dy[w], nx = x + dx[w];
					if (valid(ny, nx) && g[ny][nx] != '*') {
						if (g[ny][nx] == '#' && d[ny][nx] > d[y][x] + 1) {
							d[ny][nx] = d[y][x] + 1;
							q.push_back({ny, nx});
						}
						else if (g[ny][nx] != '#' && d[ny][nx] > d[y][x]) {
							d[ny][nx] = d[y][x];
							q.push_front({ny, nx});
						}
					}
				}
			}
			return d;
		};
		auto da = bfs(a), db = bfs(b), dc = bfs({0, 0});
		int ans = 1e9;
		for(int i =0; i<n + 2; ++i) {
			for(int j =0; j<m + 2; ++j) {
				if (g[i][j] == '*') continue;
				if (g[i][j] == '#') ans = min(ans, da[i][j] + db[i][j] + dc[i][j] - 2);
				else ans = min(ans, da[i][j] + db[i][j] + dc[i][j]);
			}
		}
		cout << ans << '\n';
	}
}