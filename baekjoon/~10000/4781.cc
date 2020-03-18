#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	double _m;
	while (cin >> n >> _m) {
		if (!n) break;
		m = _m * 100 + 0.5;
		vector<pair<int, int>> a(n);
		for(int i =0; i<n; ++i) {
			int x;
			double y;
			cin >> x >> y;
			a[i] = {x, y * 100 + 0.5};
		}
		sort(a.begin(), a.end(), [](auto& a, auto& b) {
			return a.second < b.second || a.second == b.second && a.first > b.first;
		});
		vector<pair<int, int>> c = {a.front()};
		for(int i =1; i<n; ++i) {
			if (a[i].second != a[i - 1].second && c.back().first < a[i].first)
				c.push_back(a[i]);
		}
		vector<int> d(m + 1, -1);
		d[0] = 0;
		for(int j =0; j<=m; ++j) {
			for(auto & i : c) {
				if (j < i.second) break;
				if (~d[j - i.second]) d[j] = max(d[j], d[j - i.second] + i.first);
			}
		}
		cout << *max_element(d.begin(), d.end()) << '\n';
	}
}