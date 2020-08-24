#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	while (cin >> n >> m)
	{
		if (!n && !m) break;
		vector<vector<int>> g(n, vector<int>(m)),
							py(n, vector<int>(m)),
							px(n, vector<int>(m)),
							pw(n, vector<int>(m));

		int k;
		cin >> k;
		while (k--) {
			int y, x;
			cin >> y >> x;
			g[y][x] = 1;
		}
		cin >> k;
		while (k--) {
			int y1, x1, y2, x2, t;
			cin >> y1 >> x1 >> y2 >> x2 >> t;
			g[y1][x1] = 2;
			py[y1][x1] = y2;
			px[y1][x1] = x2;
			pw[y1][x1] = t;
		}

		const int inf = 1e9;
		const int dy[] = {1,-1,0,0};
		const int dx[] = {0,0,1,-1};
		auto valid = [=](int y, int x) {
			return (y >= 0 && x >= 0 && y < n && x < m);
		};
		vector<vector<int>> d(n, vector<int>(m, inf));
		d[0][0] = 0;
		bool update;
		for(int i =0; i<n*m; ++i) {
			update = 0;
			for(int y =0; y<n; ++y) {
				for(int x =0; x<m; ++x) {
					if (d[y][x] == inf) continue;
					if (y == n - 1 && x == m - 1) continue;
					if (g[y][x] == 2) {
						if (d[py[y][x]][px[y][x]] > d[y][x] + pw[y][x]) {
							d[py[y][x]][px[y][x]] = d[y][x] + pw[y][x];
							update = 1;
						}
						continue;
					}
					for(int w =0; w<4; ++w) {
						int ny = y + dy[w], nx = x + dx[w], t;
						if (!valid(ny, nx) || g[ny][nx] == 1) continue;
						if (d[ny][nx] > d[y][x] + 1) {
							d[ny][nx] = d[y][x] + 1;
							update = 1;
						}
					}
				}
			}
		}
		if (update) {
			cout << "Never\n";
		} else if (d[n - 1][m - 1] < 1e9) {
			cout << d[n - 1][m - 1] << '\n';
		} else {
			cout << "Impossible\n";
		}
	}
}