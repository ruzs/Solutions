#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;
	vector<int> a(n + 1);
	for(int i =1; i<=n; ++i) {
		cin >> a[i];
		a[i] += a[i - 1];
		a[i] %= k;
	}
	int m; cin >> m;
	int sq = sqrt(n);
	vector<vector<tuple<int, int, int>>> q(n / sq + 1);
	for(int i =0; i<m; ++i) {
		int s, e; cin >> s >> e;
		s--;
		q[s / sq].push_back({s, e, i});
	}
	int lb = 0, rb = sq;
	vector<int> L(k, -1), R(k), ans(m);
	for(auto & qi : q) {
		sort(qi.begin(), qi.end(), 
		[](auto& a, auto& b) { return get<1>(a) < get<1>(b); });

		for(int i =0; i<=n; ++i) L[a[i]] = -1, R[a[i]] = 0;
		int r = lb, x = 0;
		for(auto & [s, e, i] : qi) {
			for(; r<=e; ++r) {
				R[a[r]] = r;
				if (r < rb) continue;
				if (!~L[a[r]]) L[a[r]] = r;
				x = max(x, R[a[r]] - L[a[r]]);
			}
			ans[i] = x;
			for(int l =s; l<min(e, rb); ++l) {
				ans[i] = max(ans[i], R[a[l]] - l);
			}
		}
		lb += sq;
		rb += sq;
	}
	for(int i : ans) cout << i << '\n';
}