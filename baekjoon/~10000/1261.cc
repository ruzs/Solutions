#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> m >> n;
	vector<string> g(n);
	for(int i =0; i<n; ++i) cin >> g[i];
	const int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	const int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [&](int y, int x) {
		return y >= 0 && x >= 0 && y < n && x < m;
	};
	deque<pair<int, int>> q;
	vector<vector<int>> d(n, vector<int>(m, 1e9));
	q.push_back({0, 0});
	d[0][0] = 0;
	while(q.size()) {
		auto [y, x] = q.front(); q.pop_front();
		if (y == n - 1 && x == m - 1) {
			cout << d[y][x];
			return 0;
		}
		for(int w =0; w<4; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (!valid(ny, nx)) continue;
			if (d[ny][nx] > d[y][x] + (g[ny][nx] == '1')) {
				d[ny][nx] = d[y][x] + (g[ny][nx] == '1');
				if (g[ny][nx] == '1') {
					q.push_back({ny, nx});
				} else {
					q.push_front({ny, nx});
				}
			}
		}
	}
}