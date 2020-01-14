#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
struct pos { int y =-1, x =-1; };
int n, m;
char g[21][21];
pos np(int y, int x, int w) {
	int nx = x + dx[w], ny = y + dy[w];
	if (nx < 0 || ny < 0 || nx == m || ny == n) return {-1, -1};
	return {ny, nx};
}
int rec(int i) {
	if (!i) return 1e5;
	int res = 1e5;
	pos a, b;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			if (g[i][j] == 'o') {
				if (a.x == -1) a = {i, j};
				else b = {i, j};
			}
		}
	}
	if (b.x == -1) return 1e5;
	for(int w =0; w<4; ++w) {
		auto na = np(a.y, a.x, w), nb = np(b.y, b.x, w);
		if (na.x == -1 && nb.x == -1) continue;
		if (na.x == -1 || nb.x == -1) return 1;
		if (g[na.y][na.x] == '#' && g[nb.y][nb.x] == '#') continue;
		g[a.y][a.x] = '.';
		g[b.y][b.x] = '.';
		g[na.y][na.x] != '#' ? g[na.y][na.x] = 'o' : g[a.y][a.x] = 'o';
		g[nb.y][nb.x] != '#' ? g[nb.y][nb.x] = 'o' : g[b.y][b.x] = 'o';
		res = min(res, rec(i - 1) + 1);
		if (g[na.y][na.x] != '#') g[na.y][na.x] = '.';
		if (g[nb.y][nb.x] != '#') g[nb.y][nb.x] = '.';
		g[a.y][a.x] = 'o';
		g[b.y][b.x] = 'o';
	}
	return res;
}
int main() {
	cin >> n >> m;
	for(int i =0; i<n; ++i) cin >> g[i];
	int ans = rec(10);
	cout << (ans < 1e5 ? ans : -1);
}
