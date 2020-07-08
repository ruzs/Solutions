#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(string & i : g) cin >> i;
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	r1--; c1--; r2--; c2--;
	constexpr int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	constexpr int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [n, m](int y, int x)
		{ return y >= 0 && x >= 0 && y < n && x < m; };
	int d[501][501]{};
	d[r1][c1] = 1;
	queue<pair<int, int>> q;
	q.push({r1, c1});
	while(q.size()) {
		auto [y, x] = q.front();
		q.pop();
		for(int w =0; w<4; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (valid(ny, nx)) {
				if (ny == r2 && nx == c2) {
					if (g[ny][nx] == '.') {
						g[ny][nx] = 'X';
						q.push({ny, nx});
					} else {
						cout << "YES";
						return 0;
					}
				} else if (g[ny][nx] == '.') {
					g[ny][nx] = 'X';
					q.push({ny, nx});
				}
			}
		}
	}
	cout << "NO";
}