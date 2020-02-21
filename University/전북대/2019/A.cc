#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1,-1,0,0};
const int dx[] = {0,0,1,-1};
int n, m, d[51][51][1 << 5];
char grid[51][51];
queue<tuple<int, int, int>> q;
map<pair<int, int>, int> mp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for(int i =0; i<n; ++i) {
		cin >> grid[i];
		for(int j =0; j<m; ++j) {
			if (grid[i][j] == 'S') q.push({i, j, 0});
			if (grid[i][j] == 'X') mp[{i, j}] = mp.size();
		}
	}
	while(q.size()) {
		auto [y, x, msk] = q.front(); q.pop();
		if (grid[y][x] == 'E' && msk + 1 == 1 << mp.size()) return cout << d[y][x][msk], 0;
		int c = grid[y][x] == 'X' ? 1 << mp[{y, x}] : 0;
		for(int w =0; w<4; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (ny < 0 || nx < 0 || ny == n || nx == m || grid[ny][nx] == '#') continue;
			if (!d[ny][nx][msk | c]) {
				d[ny][nx][msk | c] = d[y][x][msk] + 1;
				q.push({ny, nx, msk | c});
			}
		}
	}
}