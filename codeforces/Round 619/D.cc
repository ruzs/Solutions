#include <bits/stdc++.h>

using namespace std;

vector<pair<int, char>> ans;
const int dy[] = {1,-1,0,0};
const int dx[] = {0,0,1,-1};
char way[] = {'D','U','R','L'};
int n, m, k;
bool v[501][501][4];
bool dfs(int y, int x, int u, int cnt) {
	if (cnt == k) {
		cout << "YES\n" << ans.size() << '\n';
		for(auto & i : ans) cout << i.first << ' ' << i.second << '\n';
		return 1;
	}
	v[y][x][u] = 1;
	for(int w = 0; w<4; ++w) {
		int ny = y + dy[w], nx = x + dx[w];
		if (ny < 0 || nx < 0 || ny == n || nx == m) continue;
		if (!v[ny][nx][w]) {
			ans.push_back({1, way[w]});
			if (dfs(ny, nx, w, cnt + 1)) return 1;;
			ans.pop_back();
		}
	}
	v[y][x][u] = 0;
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	if (2 * (n * (m - 1) + (n - 1) * m) < k) {
		cout << "NO";
	}
	else {
		dfs(0, 0, 0, 0);
	}
}