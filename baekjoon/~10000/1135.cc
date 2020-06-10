#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for(int i =0; i<n; ++i) {
		int p;
		cin >> p;
		if (~p) g[p].push_back(i);
	}
	function<int(int)> dp = [&](int a) {
		if (g[a].empty()) return 1;
		vector<int> v;
		for(int b : g[a]) {
			v.push_back(dp(b));
		}
		sort(v.rbegin(), v.rend());
		int mx = 0;
		for(int i =0; i<v.size(); ++i) {
			mx = max(mx, v[i] + i);
		}
		return mx + 1;
	};
	cout << dp(0) - 1;
}