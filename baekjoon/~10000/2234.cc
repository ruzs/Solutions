#include <bits/stdc++.h>

using namespace std;

int n, m, a[50][50];
int v[50][50], room[2500];

constexpr int dy[] = {0, -1, 0, 1, 1, 1, -1, -1};
constexpr int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
bool imp(int y, int x) {
	return y < 0 || x < 0 || y >= n || x >= m;
}
int dfs(int y, int x, int c) {
	v[y][x] = c;
	int r = 1;
	for(int w =0; w<4; ++w) {
		if (~a[y][x] & 1 << w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (imp(ny, nx)) continue;
			if (!v[ny][nx]) r += dfs(ny, nx, c);
		}
	}
	return r;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	for(int i =0; i<n; ++i)
		for(int j =0; j<m; ++j)
			cin >> a[i][j];
	int ans1 = 0, ans2 = 0, ans3 = 0;
	for(int i =0; i<n; ++i)
		for(int j =0; j<m; ++j)
			if (!v[i][j]) {
				int sz = dfs(i, j, ++ans1);
				ans2 = max(ans2, sz);
				room[ans1] = sz;
			}
	for(int i =0; i<n; ++i)
		for(int j =0; j<m; ++j) {
			if (i > 0 && v[i][j] != v[i - 1][j])
				ans3 = max(ans3, room[v[i][j]] + room[v[i - 1][j]]);
			if (j > 0 && v[i][j] != v[i][j - 1])
				ans3 = max(ans3, room[v[i][j]] + room[v[i][j - 1]]);
		}
	cout << ans1 << '\n' << ans2 << '\n' << ans3;
}