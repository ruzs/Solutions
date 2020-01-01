#include <bits/stdc++.h>

using namespace std;

int t, n, a[101][101], d[101][101];

bool dfs(int r, int c) {
	if (!a[r][c]) return 1;
	if (d[r][c] != -1) return d[r][c];
	d[r][c] = 0;
	if (r + a[r][c] < n) d[r][c] |= dfs(r + a[r][c], c);
	if (c + a[r][c] < n) d[r][c] |= dfs(r, c + a[r][c]);
	return d[r][c];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i =0; i<n; ++i) for(int j =0; j<n; ++j) cin >> a[i][j];
		memset(d, -1, sizeof d);
		cout << (dfs(0, 0) ? "YES" : "NO") << '\n';
	}
}
