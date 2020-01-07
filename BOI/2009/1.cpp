#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[302];
int d[302][302][2];
int c(int s, int e) {
	return abs(a[s] - a[e]);
}
int dp(int l, int r, int b) {
	if (l == 0 && r == n) return 0;

	auto & ref = d[l][r][b];
	if (ref != -1) return ref;

	ref = 1e9;
	int x = k - r + l;
	if (x < 0) x = 0;

	if (l > 0) {
		if (b) ref = min(ref, dp(l - 1, r, 0) + c(r, l - 1) * x);
		else ref = min(ref, dp(l - 1, r, 0) + c(l, l - 1) * x);
	}
	if (r < n) {
		if (b) ref = min(ref, dp(l, r + 1, 1) + c(r, r + 1) * x);
		else ref = min(ref, dp(l, r + 1, 1) + c(l, r + 1) * x);
	}
	return ref;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i =1; i<=n; ++i) scanf("%d", &a[i]);
	sort(a, a + n + 1);
	int z = lower_bound(a, a + n + 1, 0) - a;
	int ans = 0;
	for(k = n; k; k--) {
		memset(d, -1, sizeof d);
		ans = max(ans, m * k - dp(z, z, 0));
	}
	printf("%d", ans);
}
