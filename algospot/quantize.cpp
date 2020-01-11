#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	int s[101]{}, s2[101]{}, d[101][11]{};
	for(int i =1; i<=n; ++i) {
		cin >> s[i];
	}
	sort(s + 1, s + n + 1);
	for(int i =1; i<=n; ++i) {
		s2[i] = s[i] * s[i] + s2[i - 1];
		s[i] += s[i - 1];
	}
	memset(d, 64, sizeof d);
	d[0][0] = 0;
	for(int k =1; k<=m; ++k) {
		for(int i =1; i<=n; ++i) {
			int l = 1.0 * s[i] / i + 0.5;
			d[i][k] = s2[i] - 2 * s[i] * l + i * l * l;
			for(int j =i - 1; j; --j) {
				l = 1.0 * (s[i] - s[j]) / (i - j) + 0.5;
				d[i][k] = min(d[i][k], d[j][k - 1] + s2[i] - s2[j] - 2 * (s[i] - s[j]) * l + (i - j) * l * l);
			}
		}
	}
	cout << d[n][m] << '\n';
}
int main() {
	int t; cin >> t;
	while(t--) solve();
}
