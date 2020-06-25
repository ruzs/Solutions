#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int mod = 1e6 + 7;
	int n, m, c;
	cin >> n >> m >> c;
	int g[51][51]{};
	for(int i =1; i<=c; ++i) {
		int y, x;
		cin >> y >> x;
		g[y][x] = i;
	}
	int d[51][51][51][51]{};
	for(int i =1; i<=n; ++i) {
		for(int j =1; j<=m; ++j) {
			if (i == 1 && j == 1) {
				d[1][1][g[i][j] ? 1 : 0][g[i][j]] = 1;
			} else if (g[i][j]) {
				for(int k =0; k<c; ++k) {
					for(int l =0; l<g[i][j]; ++l) {
						d[i][j][k + 1][g[i][j]] += d[i - 1][j][k][l] + d[i][j - 1][k][l];
						d[i][j][k + 1][g[i][j]] %= mod;
					}
				}
			} else {
				for(int l =0; l<=c; ++l) {
					for(int k =0; k<=c; ++k) {
						d[i][j][k][l] = (d[i - 1][j][k][l] + d[i][j - 1][k][l]) % mod;
					}
				}
			}
		}
	}
	for(int i =0; i<=c; ++i) {
		int sum = 0;
		for(int j =0; j<=c; ++j) {
			sum += d[n][m][i][j];
			sum %= mod;
		}
		cout << sum << ' ';
	}
}