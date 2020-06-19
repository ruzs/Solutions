#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<string> g(n);
	for(auto & i : g) cin >> i;
	constexpr int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	constexpr int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [n, m](int y, int x)
		{ return y >= 0 && x >= 0 && y < n && x < m; };
	
	vector<vector<vector<int>>> d(n, vector<vector<int>>(m, vector<int>(2)));
	queue<tuple<int, int, int, int>> q;
	q.push({0, 0, 0, k});
	d[0][0][0] = 1 << k;
	int ans = 1, qs = q.size();
	while(qs--) {
		auto [y, x, s, c] = q.front(); q.pop();
		if (y == n - 1 && x == m - 1) {
			cout << ans;
			return 0;
		}
		for(int w =0; w<4; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (!valid(ny, nx)) continue;
			if (g[ny][nx] == '1' && !s && c > 0 && (~d[ny][nx][!s] & 1 << c - 1)) {
				d[ny][nx][!s] |= 1 << c - 1;
				q.push({ny, nx, !s, c - 1});
			} else if (g[ny][nx] == '0' && (~d[ny][nx][!s] & 1 << c)) {
				d[ny][nx][!s] |= 1 << c;
				q.push({ny, nx, !s, c});
			}
		}
		if (~d[y][x][!s] & 1 << c) {
			d[y][x][!s] |= 1 << c;
			q.push({y, x, !s, c});
		}
		if (!qs) {
			qs = q.size();
			ans++;
		}
	}
	cout << -1;
}