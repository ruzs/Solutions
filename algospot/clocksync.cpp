#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> dt[10] = { {0,1,2},{3,7,9,11},{4,10,14,15},{0,4,5,6,7},
	{6,7,8,10,12},{0,2,14,15},{3,14,15},{4,5,7,14,15},{1,2,3,4,5},{3,4,5,9,13} };
	function<int(int, int)> dfs = [&](int state, int r) {
		if (state == 0) return 0;
		if (r == 10) return (int)2e6;
		int res = 2e6;
		for (int i = 0; i < 4; ++i) {
			for (int j : dt[r]) {
				int cur = (state & (3 << (j << 1))) >> (j << 1);
				cur = (cur + 1) % 4;
				state &= ~(3 << (j << 1));
				state |= (cur << (j << 1));
			}
			res = min(res, dfs(state, r + 1) + (i + 1) % 4);
		}
		return res;
	};
	int t, state, x;
	cin >> t;
	while (t--) {
		state = 0;
		for (int i = 0; i < 16; ++i) {
			cin >> x;
			x = x == 12 ? 0 : x == 3 ? 1 : x == 6 ? 2 : 3;
			state |= (x << (i << 1));
		}
		int ans = dfs(state, 0);
		if (ans == 2e6) cout << -1 << '\n';
		else cout << ans << '\n';
	}
}
