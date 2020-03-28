#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (auto& i : a) cin >> i;
	const int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	const int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [&](int y, int x) {
		return y >= 0 && x >= 0 && y < n && x < 10;
	};
	set<pair<int, int>> v;
	function<int(int, int)> dfs = [&](int y, int x) {
		v.insert({y, x});
		int res = 1;
		for (int w = 0; w < 4; ++w) {
			int ny = y + dy[w], nx = x + dx[w];
			if (valid(ny, nx) && a[ny][nx] == a[y][x] && !v.count({ny, nx}))
				res += dfs(ny, nx);
		}
		return res;
	};
	bool updated = 1;
	while(updated) {
		updated = 0;
		for(int i =0; i<n; ++i) {
			for(int j =0; j<10; ++j) {
				v.clear();
				if (a[i][j] != '0' && dfs(i, j) >= m) {
					updated = 1;
					for(auto & [y, x] : v) a[y][x] = '0';
				}
			}
		}
		for(int j =0; j<10; ++j) {
			int x = n - 1;
			for(int i = n - 1; ~i; --i) {
				if (a[i][j] != '0') {
					a[x][j] = a[i][j];
					if (x != i) a[i][j] = '0';
					x--;
				}
			}
		}
	}
	for(auto & i : a) cout << i + '\n';
}