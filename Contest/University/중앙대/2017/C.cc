#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n);
	for(int i =0; i<n; ++i) cin >> a[i].first >> a[i].second;
	vector<int> d(m + 1, -1);
	d[0] = 0;
	for(auto & i : a) {
		for(int j = m; j>=i.first; --j) {
			if (~d[j - i.first])
				d[j] = max(d[j], d[j - i.first] + i.second);
		}
	}
	cout << *max_element(d.begin(), d.end());
}