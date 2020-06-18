#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	struct dice {
		int t = 0, b = 0, n = 0, s = 0, e = 0, w = 0;
		void horizontal(int d) {
			int j = t;
			if (d > 0) {
				t = w;
				w = b;
				b = e;
				e = j;
			} else {
				t = e;
				e = b;
				b = w;
				w = j;
			}
		}
		void vertical(int d) {
			int j = t;
			if (d > 0) {
				t = n;
				n = b;
				b = s;
				s = j;
			} else {
				t = s;
				s = b;
				b = n;
				n = j;
			}
		}
	} dc;
	int n, m, y, x, k;
	cin >> n >> m >> y >> x >> k;
	int g[21][21];
	for(int i =0; i<n; ++i)
		for(int j =0; j<m; ++j)
			cin >> g[i][j];
	while(k--) {
		int d;
		cin >> d;
		if (d == 1) {
			if (x + 1 < m) {
				dc.horizontal(1);
				x++;
			} else continue;
		} else if (d == 2) {
			if (x > 0) {
				dc.horizontal(-1);
				x--;
			} else continue;
		} else if (d == 3) {
			if (y > 0) {
				dc.vertical(-1);
				y--;
			} else continue;
		} else if (d == 4) {
			if (y + 1 < n) {
				dc.vertical(1);
				y++;
			} else continue;
		}
		if (g[y][x] == 0) {
			g[y][x] = dc.b;
		} else {
			dc.b = g[y][x];
			g[y][x] = 0;
		}
		cout << dc.t << '\n';
	}
}