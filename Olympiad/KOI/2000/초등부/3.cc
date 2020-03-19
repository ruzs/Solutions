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
	const int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	const int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [&](int y, int x) {
		return y >= 0 && x >= 0 && y < n && x < m;
	};
	queue<pair<int, int>> q;
	bitset<100> v[100];
	function<void(int, int)> dfs = [&](int y, int x) {
		v[y][x] = 1;
		for(int w =0; w<4; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (valid(ny, nx) && !v[ny][nx]) {
				if (g[ny][nx]) v[ny][nx] = 1, q.push({ny, nx});
				else dfs(ny, nx);
			}
		}
	};
	dfs(0, 0);
	int qs = q.size(), cnt = 1, ls = q.size();
	while(qs--) {
		auto [y, x] = q.front(); q.pop();
		dfs(y, x);
		if (!qs) {
			if (q.empty()) {
				cout << cnt << '\n' << ls;
				return 0;
			}
			ls = qs = q.size();
			cnt++;
		}
	}
}