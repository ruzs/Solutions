#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	if (n == 1) {
		cout << "*";
		return 0;
	}
	int m = 4 * n - 3;
	n = 4 * n - 1;
	vector<string> g(n, string(m, ' '));
	for(int i =0; i<m; ++i) {
		g[0][i] = g[n-1][i] = '*';
	}
	for(int i =0; i<n; ++i) {
		g[i][0] = '*';
	}
	int y = n - 1, x = m - 1, w = 0;
	constexpr int dy[] = {-1, 0, 1, 0};
	constexpr int dx[] = {0, -1, 0, 1};
	while(1) {
		g[y][x] = '*';
		if (x == m / 2 && y == n / 2 + 1) break;
		if (g[y + dy[w] * 2][x + dx[w] * 2] == '*') {
			w = (w + 1) % 4;
		}
		y += dy[w];
		x += dx[w];
	}
	while(g[1].size() > 1) g[1].pop_back();
	for(string & i : g) cout << i << '\n';
}