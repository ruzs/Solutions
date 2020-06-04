#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) [] {
		int n;
		cin >> n;
		
		vector<pair<int, int>> p(n);
		for(auto & i : p) cin >> i.first >> i.second;

		long long ans = 1e18;
		function<void(int, int, int)> bf = [&](int msk, int s, int lft) {
			if (!lft) {
				long long x[2]{}, y[2]{};
				for(int i =0; i<n; ++i) {
					x[msk >> i & 1] += p[i].first;
					y[msk >> i & 1] += p[i].second;
				}
				ans = min(ans, (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]));
			}
			for(int i =s; i<n; ++i) {
				if (msk & 1 << i) continue;
				bf(msk | 1 << i, i + 1, lft - 1);
			}
		};
		bf(0, 0, n / 2);
		cout.precision(20);
		cout << fixed << sqrt(ans) << '\n';
	} ();
}