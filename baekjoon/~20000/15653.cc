#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	tuple<int, int, int, int> init;
	for(int i =0; i<n; ++i) {
		cin >> g[i];
		for(int j =0; j<m; ++j) {
			if (g[i][j] == 'R') get<0>(init) = i, get<1>(init) = j, g[i][j] = '.';
			else if (g[i][j] == 'B') get<2>(init) = i, get<3>(init) = j, g[i][j] = '.';
		}
	}
	const int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	const int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [&](int y, int x) {
		return y >= 0 && x >= 0 && y < n && x < m;
	};
	auto straight = [&](auto r, auto b, int w) {
		auto &[y, x] = r;
		do {
			if (g[y][x] == 'O') return r;
			y += dy[w], x += dx[w];
		} while(valid(y, x) && g[y][x] != '#' && r != b);
		y -= dy[w], x -= dx[w];
		return r;
	};
	map<tuple<int, int, int, int>, int> d;
	queue<tuple<int, int, int, int>> q;
	q.push(init);
	while(q.size()) {
		auto [ry, rx, by, bx] = q.front();
		auto c = d[q.front()]; 	q.pop();
		for(int w =0; w<4; ++w) {
			pair<int, int> r = {ry, rx}, b = {by, bx};
			r = straight(r, b, w);
			if (g[r.first][r.second] == 'O') {
				b = straight(b, pair<int, int>{-1, -1}, w);
				if (g[b.first][b.second] != 'O') {
					cout << c + 1;
					return 0;
				}
			}
			b = straight(b, r, w);
			r = straight(r, b, w);
			tuple<int, int, int, int> ns = {r.first, r.second, b.first, b.second};
			if (!d.count(ns)) {
				d[ns] = c + 1;
				q.push(ns);
			}
		}
	}
	cout << -1;
}