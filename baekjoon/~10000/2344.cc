#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 2, vector<int>(m + 2));
	for(int i =1; i<=n; ++i) {
		for(int j =1; j<=m; ++j) {
			cin >> g[i][j];
		}
	}
	int num = 0;
	for(int i =1; i<=n; ++i) g[i][0] = ++num;
	for(int j =1; j<=m; ++j) g[n + 1][j] = ++num;
	for(int i =n; i>=1; --i) g[i][m + 1] = ++num;
	for(int j =m; j>=1; --j) g[0][j] = ++num;

	const int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	const int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [&](int y, int x) {
		return y >= 1 && x >= 1 && y <= n && x <= m;
	};
	function<int(int, int, int)> dfs = [&](int y, int x, int w) {
		if (!valid(y, x)) return g[y][x];
		if (g[y][x]) w ^= 1;
		int ny = y + dy[w], nx = x + dx[w];
		return dfs(ny, nx, w);
	};
	for(int i =1; i<=n; ++i) cout << dfs(i, 1, 3) << ' ';
	for(int j =1; j<=m; ++j) cout << dfs(n, j, 2) << ' ';
	for(int i =n; i>=1; --i) cout << dfs(i, m, 1) << ' ';
	for(int j =m; j>=1; --j) cout << dfs(1, j, 0) << ' ';
}