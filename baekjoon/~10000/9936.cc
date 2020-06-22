#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int a[1000][3], d[1000][3][8][1001];
	for(int i =0; i<n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	memset(d, 127, sizeof d);
	function<int(int, int, int, int)>
	dp = [&](int y, int x, int msk, int r) {
		if (x >= 3) return dp(y + 1, 0, msk, r);
		if (y >= n) return r ? (int)-2e9 : 0;
		if (r == 0) return 0;
		int & ref = d[y][x][msk][r];
		if (ref < 2.1e9) return ref;

		ref = dp(y, x + 1, msk >> 1, r);
		if (x < 2) ref = max(ref, dp(y, x + 2, msk >> 2 | 6, r - 1) + a[y][x] + a[y][x + 1]);
		if (msk & 1 ^ 1) ref = max(ref, dp(y, x + 1, msk >> 1 | 4, r - 1) + a[y][x] + a[y - 1][x]);
		return ref;
	};
	cout << dp(0, 0, 7, k);
}