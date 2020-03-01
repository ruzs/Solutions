#include <bits/stdc++.h>

using namespace std;

int n, g[17][17], d[17][17][3];
bool valid(int r, int c, int w) {
	if (w == 0) return r <= n && c + 1 <= n && !g[r][c + 1];
	if (w == 1) return r + 1 <= n && c + 1 <= n && !g[r][c + 1] && !g[r + 1][c] && !g[r + 1][c + 1];
	if (w == 2) return r + 1 <= n && c <= n && !g[r + 1][c];
}
int dp(int r, int c, int w) {
	if (r == n && c == n) return 1;
	int & ref = d[r][c][w];
	if (ref != -1) return ref;
	ref = 0;
	if (w == 0) {
		if (valid(r, c, 0)) ref += dp(r, c + 1, 0);
		if (valid(r, c, 1)) ref += dp(r + 1, c + 1, 1);
	}
	if (w == 1) {
		if (valid(r, c, 0)) ref += dp(r, c + 1, 0);
		if (valid(r, c, 1)) ref += dp(r + 1, c + 1, 1);
		if (valid(r, c, 2)) ref += dp(r + 1, c, 2);
	}
	if (w == 2) {
		if (valid(r, c, 1)) ref += dp(r + 1, c + 1, 1);
		if (valid(r, c, 2)) ref += dp(r + 1, c, 2);
	}
	return ref;
}
int main() {
	cin >> n;
	for(int i =1; i<=n; ++i)
		for(int j =1; j<=n; ++j)
			cin >> g[i][j];
	memset(d, -1, sizeof d);
	cout << dp(1, 2, 0);
}