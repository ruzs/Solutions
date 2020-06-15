#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, w;
		cin >> n >> w;
		vector<array<int, 2>> a(n);
		for(auto & i : a) cin >> i[0];
		for(auto & i : a) cin >> i[1];
		a.push_back(a[0]);
		int ans = 1e9;
		for(int x : {0, 1, 2, 3}) {
			vector<vector<int>> d(n + 1, vector<int>(4, 1e9));
			d[0][x] = 0;
			for(int i =1; i<=n; ++i) {
				d[i][0] = d[i - 1][3];
				d[i][1] = min(d[i][0] + 1, d[i - 1][2] + (a[i][0] + a[i - 1][0] <= w ? 1 : 2));
				d[i][2] = min(d[i][0] + 1, d[i - 1][1] + (a[i][1] + a[i - 1][1] <= w ? 1 : 2));
				d[i][3] = min({d[i][0] + (a[i][0] + a[i][1] <= w ? 1 : 2), d[i][1] + 1, d[i][2] + 1, d[i - 1][0] + (a[i][0] + a[i - 1][0] <= w ? 1 : 2) + (a[i][1] + a[i - 1][1] <= w ? 1 : 2)});
			}
			ans = min(ans, d[n][x]);
		}
		cout << ans << '\n';
	}
}