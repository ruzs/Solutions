#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int g[51][51];
	struct E {
		int val, y, x;
	};
	vector<E> v(1);

	int init = 0;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			cin >> g[i][j];
			if (g[i][j] == -1) {
				v.push_back({(i + 1) * (j + 1) * (n - i) * (m - j) % k, i, j});
			}
			else if (g[i][j] == 1) {
				init = (init + (i + 1) * (j + 1) * (n - i) * (m - j)) % k;
			}
		}
	}
	bool d[2501][2500]{};
	d[0][init] = 1;
	for(int i =1; i<v.size(); ++i) {
		for(int j =0; j<k; ++j) {
			if (d[i - 1][j]) {
				d[i][j] = 1;
				d[i][(j + v[i].val) % k] = 1;
			}
		}
	}
	if (d[v.size() - 1][0]) {
		cout << 1 << '\n';
		for(int i =v.size() - 1, j = 0; i > 0; --i) {
			if (d[i - 1][(j - v[i].val + k) % k]) {
				g[v[i].y][v[i].x] = 1;
				j = (j - v[i].val + k) % k;
			} else {
				g[v[i].y][v[i].x] = 0;
			}
		}
		for(int i =0; i<n; ++i) {
			for(int j =0; j<m; ++j) cout << g[i][j] << ' ';
			cout << '\n';
		}
	} else {
		cout << -1;
	}
}