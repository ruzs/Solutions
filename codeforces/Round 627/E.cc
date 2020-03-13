#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, h, l, r;
	cin >> n >> h >> l >> r;
	vector<int> a(n + 1);
	for(int i =1; i<=n; ++i) {
		cin >> a[i];
	}
	vector<vector<int>> d(n + 1, vector<int>(h, -1));
	d[0][0] = 0;
	for(int i =1; i<=n; ++i) {
		for(int j =0; j<h; ++j) {
			if (~d[i - 1][(j - a[i] + h) % h])
				d[i][j] = max(d[i][j], d[i - 1][(j - a[i] + h) % h] + (l <= j && j <= r));
			if (~d[i - 1][(j - (a[i] - 1) + h) % h])
				d[i][j] = max(d[i][j], d[i - 1][(j - (a[i] - 1) + h) % h] + (l <= j && j <= r));
		}
	}
	int ans = 0;
	for(int j =0; j<h; ++j) ans = max(ans, d[n][j]);
	cout << ans;
}