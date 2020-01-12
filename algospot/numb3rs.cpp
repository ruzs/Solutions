#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, p, a[50][50], b[50]{};
	cin >> n >> m >> p;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<n; ++j) {
			cin >> a[i][j];
			if (a[i][j]) b[i]++;
		}
	}
	double d[101][50]{};
	d[0][p] = 1.0;
	for(int i =1; i<=m; ++i) {
		for(int j =0; j<n; ++j) {
			for(int k =0; k<n; ++k) {
				if (a[j][k]) d[i][j] += d[i - 1][k] / b[k];
			}
		}
	}
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		cout << setprecision(20) << d[m][x] << ' ';
	}
	cout << '\n';
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}
