#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, p, e;
	cin >> n >> p >> e;
	vector<pair<int, int>> a(n);
	for(auto & i : a) cin >> i.first >> i.second;
	for(int msk = 0; msk<1<<n; ++msk) {
		if (__builtin_popcount(msk) != p) continue;
		int mn = 0, mx = 0;
		for(int i =0; i<n; ++i) {
			if (msk & 1 << i) mn += a[i].first, mx += a[i].second;
		}
		if (mn <= e && e <= mx) {
			vector<int> ans(n);
			for(int i =0; i<n; ++i) {
				if (msk & 1 << i) ans[i] += a[i].first, e -= a[i].first;
			}
			for(int i =0; i<n && e > 0; ++i) {
				if (msk & 1 << i && ans[i] < a[i].second) {
					int d = min(e, a[i].second - ans[i]);
					e -= d;
					ans[i] += d;
				}
			}
			for(int i : ans) cout << i << ' ';
			return 0;
		}
	}
	cout << -1;
}