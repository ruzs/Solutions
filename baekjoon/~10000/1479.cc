#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, a[4];
	cin >> s;
	for(int i =0; i<4; ++i) cin >> a[i];
	
	bool c[2501][51][16]{};
	pair<int, int> d[2501][51][16];
	function<pair<int, int>(int, int, int)> dp = [&](int x, int r, int msk) {
		if (x == s.size()) return msk == 15 ? make_pair(0, 0) : make_pair(100000, -100000);
		auto & ref = d[x][r][msk];
		if (c[x][r][msk]) return ref;
		ref = dp(x + 1, max(0, r - 1), msk);
		for(int i =0; i<4; ++i) {
			if (msk >> i & 1 ^ 1 && s.substr(x, a[i].size()) == a[i]) {
				auto tmp = dp(x, max(r, (int)a[i].size()), msk | 1 << i);
				int cnt = a[i].size() > r ? a[i].size() - r : 0;
				ref = {min(ref.first, tmp.first + cnt), max(ref.second, tmp.second + cnt)};
			}
		}
		c[x][r][msk] = 1;
		return ref;
	};
	auto ans = dp(0, 0, 0);
	cout << ans.first << ' ' << ans.second;
}