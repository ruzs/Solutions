#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<string> g(n);
	for(int i =0; i<n; ++i) cin >> g[i];
	int mx = 0, sy, sx;
	for(int i =0; i+k<=n; ++i) {
		for(int j =0; j+k<=m; ++j) {
			int sum =0;
			for(int y =1; y+1<k; ++y) {
				for(int x =1; x+1<k; ++x) {
					sum += g[i + y][j + x] == '*';
				}
			}
			if (mx < sum) {
				mx = sum;
				sy = i;
				sx = j;
			}
		}
	}
	for(int i =1; i+1<k; ++i) {
		g[sy + i][sx] = '|';
		g[sy + i][sx + k - 1] = '|';
		g[sy][sx + i] = '-';
		g[sy + k - 1][sx + i] = '-';
	}
	g[sy][sx] = g[sy + k - 1][sx] = g[sy][sx + k - 1] = g[sy + k - 1][sx + k - 1] = '+';
	cout << mx << '\n';
	for(auto & i : g) cout << i << '\n';
}