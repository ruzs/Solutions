#include <bits/stdc++.h>

using namespace std;

long long d[1 << 16][16];
long long dp(int msk, int l, int n, int k, int a[]) {
	if (msk + 1 == 1 << n) return 1;
	long long & ref = d[msk][l];
	if (ref != -1) return ref;

	ref = 0;
	for(int i =0; i<n; ++i) {
		if (msk & (1 << i)) continue;
		if (abs(a[l] - a[i]) > k)
			ref += dp(msk | (1 << i), i, n, k, a);
	}
	return ref;
}
int main() {
	int n, a[16], k;
	cin >> n >> k;
	for(int i =0; i<n; ++i) cin >> a[i];
	memset(d, -1 ,sizeof d);
	long long ans = 0;
	for(int i =0; i<n; ++i) ans += dp(1 << i, i, n, k, a);
	cout << ans;
}