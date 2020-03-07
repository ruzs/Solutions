#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, dp[1 << 15][5]{};
	dp[0][0] = 1;
	for (int j = 1; j <= 256; ++j) {
		int jj = j * j;
		for (int r = 1; r <= 4; ++r) {
			for (int i = jj; i < 1 << 15; ++i) {
				dp[i][r] += dp[i - jj][r - 1];
			}
		}
	}
	while(cin >> n) {
		if (!n) break;
		cout << dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1] << '\n';
	}
}