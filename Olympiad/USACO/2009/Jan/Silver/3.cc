#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
int n, m, sx, sy=-1, ex, ey, d[101][101][4];
char g[101][101];

bool valid(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < m && g[y][x] != '*';
}
int main() {
	cin >> m >> n;
	for(int i =0; i<n; ++i) {
		cin >> g[i];
		for(int j =0; j<m; ++j)
			if (g[i][j] == 'C') {
				if (sy == -1) sy = i, sx = j;
				else ey = i, ex = j;
			}
	}

	queue<tuple<int, int, int>> q;
	memset(d, 64, sizeof d);
	for(int i =0; i<4; ++i) {
		q.push({sy, sx, i});
		d[sy][sx][i] = 0;
	}

	while(q.size()) {
		auto [r, c, w] = q.front(); q.pop();
		int nr = r + dy[w], nc = c + dx[w], nw;
		if (valid(nr, nc) && d[nr][nc][w] > d[r][c][w]) {
			d[nr][nc][w] = d[r][c][w];
			q.push({ nr, nc, w });
		}
		nw = (w + 1) % 4;
		if (d[r][c][nw] > d[r][c][w] + 1) {
			d[r][c][nw] = d[r][c][w] + 1;
			q.push({ r, c, nw });
		}
		nw = (w + 3) % 4;
		if (d[r][c][nw] > d[r][c][w] + 1) {
			d[r][c][nw] = d[r][c][w] + 1;
			q.push({ r, c, nw });
		}
	}
	cout << min({ d[ey][ex][0],d[ey][ex][1],d[ey][ex][2],d[ey][ex][3] });
}