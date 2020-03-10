#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	struct point {
		int y, x;
	} a1, a2, b1, b2;
	cin >> b1.y >> b1.x;
	cin >> b2.y >> b2.x;
	cin >> a1.y >> a1.x;
	cin >> a2.y >> a2.x;

	const int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	const int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [&](int y, int x) {
		return y >= 0 && x >= 0 && y <= n && x <= m;
	};
	auto solve = [&](point& a1, point& a2, point& b1, point& b2) {
		int g[101][101]{};
		g[b1.y][b1.x] = 1;
		g[b2.y][b2.x] = 1;
		pair<int, int> f[101][101]{};
		bool v[101][101]{};
		auto bfs = [&](point & s, point & e) {
			queue<point> q;
			q.push(s);
			v[s.y][s.x] = 1;
			int qs = q.size(), cnt = 0;
			while(qs--) {
				auto [y, x] = q.front(); q.pop();
				if (y == e.y && x == e.x) return cnt;
				for(int w =0; w<4; ++w) {
					int ny = y + dy[w], nx = x + dx[w];
					if (valid(ny, nx) && !g[ny][nx] && !v[ny][nx]) {
						v[ny][nx] = 1;
						f[ny][nx] = {y, x};
						q.push({ny, nx});
					}
				}
				if (!qs) {
					qs = q.size();
					cnt++;
				}
			}
			return -1;
		};
		int ans = bfs(a1, a2);
		auto [fy, fx] = a2;
		while(fy != a1.y || fx != a1.x) {
			g[fy][fx] = 1;
			tie(fy, fx) = f[fy][fx];
		}
		g[fy][fx] = 1;
		g[b2.y][b2.x] = 0;
		memset(v, 0, sizeof v);
		int ans2 = bfs(b1, b2);
		if (~ans2) return ans + ans2;
		else return -1;
	};
	int ans1 = solve(a1, a2, b1, b2);
	int ans2 = solve(b1, b2, a1, a2);
	if (~ans1 && ~ans2) cout << min(ans1, ans2);
	else if (~ans1) cout << ans1;
	else if (~ans2) cout << ans2;
	else cout << "IMPOSSIBLE";
}