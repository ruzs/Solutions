#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a, b;
	for(int i =0; i<n; ++i) {
		int x, y;
		cin >> x >> y;
		if (x > 1000) b.push_back({x, y});
		else a.push_back({x, y});
	}
	vector<int> d(1000 * n + 1, -1);
	d[0] = 0;
	for(auto & i : a) {
		for(int j =1000 * n; j>=i.first; --j) {
			if (~d[j - i.first]) 
				d[j] = max(d[j], d[j - i.first] + i.second);
		}
	}
	int ans = -1;
	for(int i =m; i<(int)d.size(); ++i)
		if (~d[i]) ans = max(ans, int(1000.0 * d[i] / i));
	for(auto & j : b) {
		ans = max(ans, int(1000.0 * j.second / j.first));
		for(int i =0; i<m; ++i) {
			if (~d[i]) ans = max(ans, int(1000.0 * (d[i] + j.second) / (i + j.first)));
		}
	}
	cout << ans;
}