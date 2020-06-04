#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t, ey, ex;
	char g[500][501];
	int d[500][500][2];
	constexpr int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	constexpr int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	
	cin >> n >> t >> ey >> ex;
	ey--; ex--;
	for(int i =0; i<n; ++i) cin >> g[i];
	memset(d, 64, sizeof d);
	priority_queue<tuple<int, int, int, int>> pq;
	auto valid = [n](int y, int x)
		{ return y >= 0 && x >= 0 && y < n && x < n; };
	d[0][0][0] = 0;
	pq.emplace(0, 0, 0, 0);
	while(pq.size()) {
		auto [c, y, x, s] = pq.top(); pq.pop();
		if (d[y][x][s] != -c) continue;
		if (y == ey && x == ex) {
			cout << d[y][x][s];
			break;
		}
		if (s) {
			if (d[y][x][0] > d[y][x][1]) {
				d[y][x][0] = d[y][x][1];
				pq.emplace(-d[y][x][0], y, x, 0);
			}
			for(int w =0; w<4; ++w) {
				int ny = y + dy[w], nx = x + dx[w];
				while(valid(ny, nx) && g[ny][nx] != '#') {
					ny += dy[w];
					nx += dx[w];
				}
				int nc = -c + 1;
				if (valid(ny, nx) && d[ny][nx][1] > nc) {
					d[ny][nx][1] = nc;
					pq.emplace(-nc, ny, nx, 1);
				}
			}
		} else {
			if (d[y][x][1] > d[y][x][0] + t) {
				d[y][x][1] = d[y][x][0] + t;
				pq.emplace(-d[y][x][1], y, x, 1);
			}
			for(int w = 0; w<4; ++w) {
				int ny = y + dy[w], nx = x + dx[w];
				int nc = -c + 1;
				if (valid(ny, nx) && d[ny][nx][0] > nc) {
					d[ny][nx][0] = nc;
					pq.emplace(-nc, ny, nx, 0);
				}
			}
		}
	}
}