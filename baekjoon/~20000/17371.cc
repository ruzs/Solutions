#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for(auto & i : p) cin >> i.first >> i.second;
	int x;
	auto dist = [](auto & a, auto & b) {
		int dx = a.first - b.first;
		int dy = a.second - b.second;
		return dx * dx + dy * dy;
	};
	int mnd = 1e9;
	for(int i =0; i<n; ++i) {
		int mxd = 0;
		for(int j =0; j<n; ++j) {
			int d = dist(p[i], p[j]);
			if (mxd < d) mxd = d;
		}
		if (mnd > mxd) mnd = mxd, x = i;
	}
	cout << p[x].first << ' ' << p[x].second;
}