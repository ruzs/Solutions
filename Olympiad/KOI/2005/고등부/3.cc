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
	const int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
	const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
	auto valid = [&](int y, int x) {
		return y >= 0 && x >= 0 && y < n && x < m;
	};
	priority_queue<tuple<int, int, int, int>> q;
	int d[100][100][4]{};
	memset(d, 64, sizeof d);
	int ey, ex, ew;
	cin >> ey >> ex >> ew;
	q.emplace(0, ey - 1, ex - 1, ew - 1);
	d[ey - 1][ex - 1][ew - 1] = 0;
	cin >> ey >> ex >> ew;
	ey--; ex--; ew--;
	int qs = 1, cnt = 0;
	
	while(qs--) {
		auto [c, y, x, w] = q.top(); q.pop();
		if (y == ey && x == ex && w == ew) {
			cout << cnt;
			return 0;
		}
		if (d[y][x][w] < -c) continue;
		int nc = -c + 1;
		for(int i =1; i<=3; ++i) {
			int ny = y + i * dy[w], nx = x + i * dx[w];
			if (valid(ny, nx) && !g[ny][nx]) {
				if (d[ny][nx][w] > nc) {
					d[ny][nx][w] = nc;
					q.emplace(-nc, ny, nx, w);
				}
			} else break;
		}
		int nw = (w + 2) % 4;
		if (d[y][x][nw] > nc) {
			d[y][x][nw] = nc;
			q.emplace(-nc, y, x, nw);
		}
		nw ^= 1;
		if (d[y][x][nw] > nc) {
			d[y][x][nw] = nc;
			q.emplace(-nc, y, x, nw);
		}
		if (!qs) {
			qs = q.size();
			cnt++;
		}
	}
}