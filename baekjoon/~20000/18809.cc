#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
int g[50][50];
constexpr int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
auto valid = [](int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < m;
};
vector<pair<int, int>> p;
int bfs(int x, int y) {
	queue<pair<int, int>> qa, qb;
	vector<vector<int>> d(n, vector<int>(m));
	for(int i =0; i<p.size(); ++i) {
		if (x & 1 << i) {
			qa.push(p[i]);
			d[p[i].first][p[i].second] = 1;
		}
		if (y & 1 << i) {
			qb.push(p[i]);
			d[p[i].first][p[i].second] = 2;
		}
	}
	int cnt = 0;
	while(qa.size() && qb.size()) {
		int qs = qa.size();
		while(qs--) {
			auto [r, c] = qa.front(); qa.pop();
			if (d[r][c] == 3) continue;
			d[r][c] = -1;
			for(int w = 0; w<4; ++w) {
				int nr = r + dy[w], nc = c + dx[w];
				if (valid(nr, nc) && !d[nr][nc] && g[nr][nc]) {
					d[nr][nc] = 1;
					qa.push({nr, nc});
				}
			}
		}
		qs = qb.size();
		while(qs--) {
			auto [r, c] = qb.front(); qb.pop();
			d[r][c] = -1;
			for(int w =0; w<4; ++w) {
				int nr = r + dy[w], nc = c + dx[w];
				if (valid(nr, nc)) {
					if (d[nr][nc] == 1) {
						cnt++;
						d[nr][nc] = 3;
					} else if (d[nr][nc] == 0 && g[nr][nc]) {
						d[nr][nc] = 2;
						qb.push({nr, nc});
					}
				}
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> a >> b;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			cin >> g[i][j];
			if (g[i][j] == 2) {
				p.push_back({i, j});
			}
		}
	}
	int ans = 0;
	for(int i =0; i<1<<p.size(); ++i) {
		if (__builtin_popcount(i) != a + b) continue;
		for(int j =i; j; j = (j - 1) & i) {
			if (__builtin_popcount(j) == a)
				ans = max(ans, bfs(j, i ^ j));
		}
	}
	cout << ans;
}