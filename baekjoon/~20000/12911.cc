#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int mod = 1e9 + 7;
	int n, k;
	cin >> n >> k;
	int d[10][100005];
	for(int i =1; i<=k; ++i) d[0][i] = 1;
	long long sum = k, tmp;
	for(int i =1; i<n; ++i) {
		tmp = 0;
		for(int j =1; j<=k; ++j) {
			d[i][j] = sum;
			for(int l =j+j; l<=k; l+=j)
				d[i][j] = (d[i][j] - d[i - 1][l] + mod) % mod;
			tmp = (tmp + d[i][j]) % mod;
		}
		sum = tmp;
	}
	int ans = 0;
	for(int i =1; i<=k; ++i)
		ans = (ans + d[n - 1][i]) % mod;
	cout << ans;
}