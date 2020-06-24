#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int mod = 1e9 + 9;
	int d[1005][1005]{};
	d[0][0] = 1;
	for(int i =1; i<=1000; ++i) {
		for(int j =0; j<=1000; ++j) {
			int & ref = d[i][j];
			if (j > 0) ref = (ref + d[i - 1][j - 1]) % mod;
			if (j > 1) ref = (ref + d[i - 1][j - 2]) % mod;
			if (j > 2) ref = (ref + d[i - 1][j - 3]) % mod;
		}
	}
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << d[m][n] << '\n';
	}
}