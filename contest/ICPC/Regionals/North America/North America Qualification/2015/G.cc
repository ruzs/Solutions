#include <bits/stdc++.h>

using namespace std;

int d[1 << 16];
int dp(int msk, int n, int a[]) {
	if (msk + 1 == 1 << n + 1) return 0;
	int & ref = d[msk];
	if (ref != -1) return ref;
	ref = 1e9;

	if (msk & (1 << n)) {
		for(int i =0; i<n; ++i) if (msk & (1 << i)) 
			ref = min(ref, dp(msk ^ (1 << i) ^ (1 << n), n, a) + a[i]);
	}
	else {
		for(int i =0; i<n; ++i) if (~msk & (1 << i)) {
			for(int j =i + 1; j<n; ++j) if (~msk & (1 << j))
				ref = min(ref, dp(msk ^ (1 << n) ^ (1 << i) ^ (1 << j), n, a) + max(a[i], a[j]));
			ref = min(ref, dp(msk ^ (1 << n) ^ (1 << i), n, a) + a[i]);
		}
	}
	return ref;
}
int main() {
	int n, a[16];
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	memset(d, -1, sizeof d);
	cout << dp(0, n, a);
}