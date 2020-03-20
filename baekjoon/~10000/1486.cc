#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, dh, t;
	cin >> n >> m >> dh >> t;
	vector<string> g(n);
	for(int i =0; i<n; ++i) cin >> g[i];
	const int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	const int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [&](int y, int x) {
		return y >= 0 && x >= 0 && y < n && x < m;
	};
	auto enc = [](char c) {
		return isupper(c) ? c - 'A' : c - 'a' + 26;
	};
	auto dist = [dh](int from, int to) {
		if (abs(from - to) > dh) return (int)1e9;
		if (from >= to) return 1;
		return (to - from) * (to - from);
	};
	auto dijkstra = [&](int r, int c) {
		priority_queue<tuple<int, int, int>> pq;
		vector<vector<int>> d(n, vector<int>(m, 1e9));
		pq.push({0, r, c});
		d[r][c] = 0;
		while(pq.size()) {
			auto [c, y, x] = pq.top(); pq.pop();
			for(int w =0; w<4; ++w) {
				int ny = y + dy[w], nx = x + dx[w];
				if (!valid(ny, nx)) continue;
				int nc = -c + dist(enc(g[y][x]), enc(g[ny][nx]));
				if (d[ny][nx] > nc) {
					d[ny][nx] = nc;
					pq.push({-nc, ny, nx});
				}
			}
		}
		return d;
	};
	vector<vector<int>> go = dijkstra(0, 0);
	int ans = 0;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			if (go[i][j] + dijkstra(i, j)[0][0] > t) continue;
			ans = max(ans, enc(g[i][j]));
		}
	}
	cout << ans;
}