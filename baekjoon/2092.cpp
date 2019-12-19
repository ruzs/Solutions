#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5, mod = 1e6;

int n, m, s, e, a[201], d[201][4001];
int dp(int n, int k) {
	if (!k) return 1;
	if (k < 0 || !n) return 0;
	int & ref = d[n][k];
	if (ref != -1) return ref;
	ref = 0;
	for(int i =0; i<=a[n]; ++i) {
		ref += dp(n - 1, k - i);
		ref %= mod;
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(d, -1, sizeof d);
	cin >> n >> m >> s >> e;
	for(int i =0, x; i < m; ++i) cin >> x, a[x]++;
	int ans = 0;
	for(int i =s; i<=e; ++i) {
		ans += dp(n, i);
		ans %= mod;
	}
	cout << ans;
}
