#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n);
	for(int i =0; i<n; ++i) cin >> a[i].first;
	for(int i =0; i<n; ++i) cin >> a[i].second;
	vector<int> d(10001, -1);
	d[0] = 0;
	for(auto & i : a) {
		for(int j =10000; j >= i.second; --j) {
			if (~d[j - i.second]) d[j] = max(d[j], d[j - i.second] + i.first);
		}
	}
	for(int i =0; i<=10000; ++i) {
		if (d[i] >= m) {
			cout << i;
			return 0;
		}
	}
}