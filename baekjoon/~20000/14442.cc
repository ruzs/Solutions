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
	
	vector<vector<vector<int>>> d(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
	queue<tuple<int, int, int>> q;
	q.push({0, 0, k});
	d[0][0][k] = 1;
	while(q.size()) {
		auto [y, x, c] = q.front(); q.pop();
		for(int w =0; w<4; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (!valid(ny, nx)) continue;
			if (g[ny][nx] == '1' && c > 0 && d[ny][nx][c - 1] == -1) {
				d[ny][nx][c - 1] = d[y][x][c] + 1;
				q.push({ny, nx, c - 1});
			} else if (g[ny][nx] == '0' && d[ny][nx][c] == -1) {
				d[ny][nx][c] = d[y][x][c] + 1;
				q.push({ny, nx, c});
			}
		}
	}
	int ans = 1e9;
	for(int i =0; i<=k; ++i) {
		if (d[n-1][m-1][i] != -1) ans = min(ans, d[n-1][m-1][i]);
	}
	if (ans < 1e9) cout << ans;
	else cout << -1;
}