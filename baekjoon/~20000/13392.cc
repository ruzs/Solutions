#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int d[10005][10];
	memset(d, 64, sizeof d);
	d[0][0] = 0;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<10; ++j) {
			if (d[i][j] < 1e9) {
				int x = (b[i] & 15) - ((a[i] & 15) + j) % 10;
				if (x == 0) d[i + 1][j] = min(d[i + 1][j], d[i][j]);
				else if (x < 0) {
					d[i + 1][(j + x + 10) % 10] = min(d[i + 1][(j + x + 10) % 10], d[i][j] + (x + 10) % 10);
					d[i + 1][j] = min(d[i + 1][j], d[i][j] - x);
				}
				else {
					d[i + 1][(j + x) % 10] = min(d[i + 1][(j + x) % 10], d[i][j] + x);
					d[i + 1][j] = min(d[i + 1][j], d[i][j] + 10 - x);
				}
			}
		}
	}
	cout << *min_element(&d[n][0], &d[n][10]);
}