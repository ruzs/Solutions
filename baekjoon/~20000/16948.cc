#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, sx, sy, ex, ey;
	cin >> n >> sy >> sx >> ey >> ex;
	constexpr int dy[] = {-2, -2, 2, 2, 0, 0};
	constexpr int dx[] = {1, -1, -1, 1, 2, -2};
	auto valid = [n](int y, int x)
		{ return y >= 0 && x >= 0 && y < n && x < n; };
	int g[200][200]{};
	queue<pair<int, int>> q;
	q.push({sy, sx});
	g[sy][sx] = 1;
	while(q.size()) {
		auto [y, x] = q.front(); q.pop();
		for(int w =0; w<6; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (valid(ny, nx) && !g[ny][nx]) {
				g[ny][nx] = g[y][x] + 1;
				q.push({ny, nx});
			}
		}
	}
	cout << g[ey][ex] - 1;
}