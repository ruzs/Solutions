#include <bits/stdc++.h>
using namespace std;

const int m = 1e7;
int d[101][101];
int dp(int r, int f) {
	if (!r) return 1;
	int & ref = d[r][f];
	if (ref != -1) return ref;

	ref = 0;
	for(int i =1; i<=r; ++i) {
		ref += (1LL * dp(r - i, i) * (f + i - 1)) % m;
		ref %= m;
	}
	return ref;
}
int main() {
	memset(d, -1, sizeof d);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int ans = 0;
		for(int i =1; i<=n; ++i) {
			ans = (ans + dp(n - i, i)) % m;
		}
		cout << ans << '\n';
	}
}
