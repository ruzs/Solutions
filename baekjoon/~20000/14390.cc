#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> a(n + 1);
	for(int i =1; i<=n; ++i) cin >> a[i];
	vector<vector<int>> d(n + 1, vector<int>(1 << m, 1e9));
	d[0][0] = 0;
	for(int y =1; y<=n; ++y) {
		for(int i =0; i<1<<m; ++i) {
			if (d[y - 1][i] == 1e9) continue;
			for(int j =0; j<1<<m; ++j) {
				int cnt = 0;
				for(int x =0; x<m; ++x) {
					if (a[y][x] == '#') continue;
					if ((y == 0 || i >> x & 1 ^ 1 || a[y - 1][x] == '#') && j >> x & 1) cnt++;
					if (j >> x & 1 ^ 1 && (!x || a[y][x - 1] == '#' || j >> x - 1 & 1)) cnt++;
				}
				d[y][j] = min(d[y][j], d[y - 1][i] + cnt);
			}
		}
	}
	cout << *min_element(d[n].begin(), d[n].end());
}