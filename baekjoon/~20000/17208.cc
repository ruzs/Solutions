#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, l;
	cin >> n >> m >> l;
	vector<pair<int, int>> a(n);
	for(int i =0; i<n; ++i) cin >> a[i].first >> a[i].second;
	vector<vector<int>> d(m + 1, vector<int>(l + 1, -1));
	d[0][0] = 0;
	for(auto & i : a) {
		for(int j =m; j>=i.first; --j) {
			for(int k =l; k>=i.second; --k) {
				if (~d[j-i.first][k-i.second])
					d[j][k] = max(d[j][k], d[j-i.first][k-i.second] + 1);
			}
		}
	}
	int ans = 0;
	for(auto & i : d) for(int j : i) ans = max(ans, j);
	cout << ans;
}