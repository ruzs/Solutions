#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i =1; i<=n; ++i) cin >> a[i];
	int m; cin >> m;
	const int sq = 315;
	vector<vector<tuple<int, int, int>>> q(n / sq + 1);
	for(int i =0; i<m; ++i) {
		int s, e; cin >> s >> e;
		q[s / sq].push_back({s, e, i});
	}
	vector<int> ans(m);
	int sl = 0, sr = sq;
	for(auto & qi : q) {
		sort(qi.begin(), qi.end(),
		[](auto& a, auto& b) {return get<1>(a) < get<1>(b);});
		vector<int> cnt(100001);
		int r = sl, x = 0;
		for(auto & [s, e, i] : qi) {
			for(; r<=e; ++r) {
				if (r < sr) continue;
				cnt[a[r]]++;
				x = max(x, cnt[a[r]]);
			}
			ans[i] = x;
			for(int l =s; l<=min(e, sr - 1); ++l) {
				cnt[a[l]]++;
				ans[i] = max(ans[i], cnt[a[l]]);
			}
			for(int l =s; l<=min(e, sr - 1); ++l) {
				cnt[a[l]]--;
			}
		}
		sl += sq;
		sr += sq;
	}
	for(int i : ans) cout << i << '\n';
}