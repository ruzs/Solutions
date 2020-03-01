#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n, g[10][10], ans = 1e9;
void rec(int mask, int a, int c) {
	if (mask + 1 == 1 << n) {
		if (g[a][0]) ans = min(ans, c + g[a][0]);
		return;
	}
	for(int b =0; b<n; ++b) {
		if (~mask & (1 << b) && g[a][b]) {
			rec(mask | (1 << b), b, c + g[a][b]);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =0; i<n; ++i) for(int j =0; j<n; ++j) cin >> g[i][j];
	rec(1, 0, 0);
	cout << ans;
}
