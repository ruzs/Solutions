#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int d[4][2][2] = {
		{{1, 0}, {0, 1}},
		{{0, 1}, {1, 1}},
		{{1, 0}, {1, -1}},
		{{1, 0}, {1, 1}} };
	int t, n, m;
	vector<string> a;
	function<int(int, int)> dfs = [&](int r, int c) {
		if (r == n) return 1;
		if (c == m) return dfs(r + 1, 0);
		if (a[r][c] != '.') return dfs(r, c + 1);
		int res = 0;
		for (int w = 0; w < 4; ++w) {
			int nr = r + d[w][0][0], nc = c + d[w][0][1];
			int mr = r + d[w][1][0], mc = c + d[w][1][1];
			if (nr == n || mr == n || nc == m || mc == m || nc < 0 || mc < 0) continue;
			if (a[nr][nc] == '.' && a[mr][mc] == '.') {
				a[nr][nc] = '#';
				a[mr][mc] = '#';
				res += dfs(r, c + 1);
				a[nr][nc] = '.';
				a[mr][mc] = '.';
			}
		}
		return res;
	};
	cin >> t;
	while (t--) {
		cin >> n >> m;
		a.resize(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		cout << dfs(0, 0) << '\n';
	}
}
