#include <bits/stdc++.h>

using namespace std;

int n, open;
long long k, d[51][51];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	d[0][0] = 1;
	for(int i =1; i<=50; ++i) {
		for(int j =0; j<=50; ++j) {
			if (j > 0) d[i][j] += d[i - 1][j - 1];
			if (j < 50) d[i][j] += d[i - 1][j + 1];
		}
	}
	if ((1LL << n) - d[n][0] <= k) {
		cout << -1;
		return 0;
	}
	for(int i =n; i; --i) {
		long long x = (1LL << (i - 1)) - (open < 0 ? 0 : d[i - 1][open + 1]);
		if (x > k) cout << '(', open++;
		else k -= x, cout << ')', open--;
		if (open < 0) open -= 10000;
	}
}
