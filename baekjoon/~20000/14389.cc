#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(auto & i : a) cin >> i;
	int d[10][25][1 << 10];
	memset(d, -1, sizeof d);
	int all = (1 << n) - 1;
	function<int(int, int, int)> dp = [&](int y, int x, int msk) {
		if (y < 0) return dp(n - 1, x + 1, msk);
		if (x == m) {
			int ret = 0;
			for(int i =0; i<n; ++i) ret += msk >> i & 1 ^ 1;
			return ret;
		}
		int & ref = d[y][x][msk & all];
		if (~ref) return ref;
		if (a[y][x] == '1')
			return ref = dp(y - 1, x, msk << 1 | 1) + (msk >> n - 1 & 1 ^ 1) + 1;
		if (y - 1 >= 0 && a[y - 1][x] != '1' && (msk >> n - 2 & 3 ^ 3) == 3)
			return ref = max(dp(y - 1, x, msk << 1) + (msk >> n - 1 & 1 ^ 1), dp(y - 2, x, msk << 2 | 3) + 16);
		return ref = max(dp(y - 1, x, msk << 1) + (msk >> n - 1 & 1 ^ 1), dp(y - 1, x, msk << 1 | 1) + (msk >> n - 1 & 1 ^ 1) + 1);
	};
	cout << dp(n - 1, 0, all);
}