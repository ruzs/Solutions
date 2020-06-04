#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int g[11][11];
	for(int i =0; i<n; ++i) for(int j =0; j<n; ++j) cin >> g[i][j];
	function<int(int, int, int)>
	bf = [&](int yy, int msk, int cnt) {
		if (yy >= n + n) return cnt;
		int y = yy < n ? yy : n - 1;
		int x = yy < n ? 0 : yy + 1 - n;
		int ret = bf(yy + 2, msk << 1, cnt);
		while(x < n && y >= 0) {
			if (g[y][x] && !(msk >> x & 1))
				ret = max(ret, bf(yy + 2, (msk | 1 << x) << 1, cnt + 1));
			x++; y--;
		}
		return ret;
	};
	cout << bf(0, 0, 0) + bf(1, 0, 0);
}