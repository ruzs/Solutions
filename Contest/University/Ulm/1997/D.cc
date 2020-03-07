#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, n, m;
	while (cin >> h >> n >> m) {
		if (!h && !n && !m) break;
		vector<vector<string>> g(h, vector<string>(n));
		queue<tuple<int, int, int>> q;
		for(int i =0; i<h; ++i) {
			for(int j =0; j<n; ++j) {
				cin >> g[i][j];
				for(int k =0; k<m; ++k) {
					if (g[i][j][k] == 'S') q.emplace(i, j, k);
				}
			}
		}
		int qs = q.size(), cnt = 0, ans = -1;
		const int dz[] = {0, 0, 0, 0, 1, -1};
		const int dy[] = {1, 0, -1, 0, 0, 0};
		const int dx[] = {0, -1, 0, 1, 0, 0};
		auto valid = [&](int z, int y, int x) {
			return z >= 0 && y >= 0 && x >= 0 && z < h && y < n && x < m;
		};
		while(qs--) {
			auto [z, y, x] = q.front(); q.pop();
			if (g[z][y][x] == 'E') {
				ans = cnt;
				break;
			}
			for(int w =0; w<6; ++w) {
				int nz = z + dz[w], ny = y + dy[w], nx = x + dx[w];
				if (!valid(nz, ny, nx) || g[nz][ny][nx] == '#') continue;
				if (g[nz][ny][nx] == '.') g[nz][ny][nx] = '#';
				q.emplace(nz, ny, nx);
			}
			if (!qs) {
				qs = q.size();
				cnt++;
			}
		}
		if (~ans) cout << "Escaped in " << ans << " minute(s).\n";
		else cout << "Trapped!\n";
	}
}