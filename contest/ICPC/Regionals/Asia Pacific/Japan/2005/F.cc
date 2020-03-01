#include <bits/stdc++.h>

using namespace std;

const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0};
int n, m, x, g[11][11];
char mp[21][21];
pair<int, int> p[11];

void bfs(int src) {
	queue<pair<int, int>> q;
	q.push(p[src]);
	int d[21][21]{};
	d[p[src].first][p[src].second] = 1;

	while(q.size()) {
		auto [y, x] = q.front(); q.pop();
		for(int w =0; w<4; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (ny < 0 || nx < 0 || ny == n || nx == m || mp[ny][nx] == 'x') continue;
			if (!d[ny][nx]) {
				d[ny][nx] = d[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
	for(int i =0; i<=x; ++i) {
		g[src][i] = d[p[i].first][p[i].second] - 1;
		if (g[src][i] < 0) g[src][i] = 1e9;
	}
}

int dp[11][1 << 11];
int go(int n, int msk) {
	if (msk + 1 == 1 << (x + 1)) return 0;
	int &ref = dp[n][msk];
	if (ref != -1) return ref;
	ref = 1e9;
	for(int i =1; i<=x; ++i) {
		if (msk & (1 << i)) continue;
		ref = min(ref, go(i, msk | (1 << i)) + g[n][i]);
	}
	return ref;
}
int main() {
	while(cin >> m >> n) {
		if (!m && !n) break;
		x = 0;
		for(int i =0; i<n; ++i) {
			cin >> mp[i];
			for(int j =0; j<m; ++j) {
				if (mp[i][j] == 'o') p[0] = {i, j};
				if (mp[i][j] == '*') p[++x] = {i, j};
			}
		}
		for(int i =0; i<=x; ++i) bfs(i);
		memset(dp, -1, sizeof dp);
		int ans = go(0, 1);
		cout << (ans < 1e9 ? ans : -1) << '\n';
	}
}