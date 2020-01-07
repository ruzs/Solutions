#include <bits/stdc++.h>
using namespace std;

int n, m, a[1001];
long long w[1001], d[1001][1001][2];
long long c(int s, int e, long long t) {
	if (e < 1 || e > n) return 1e18;
	return t * abs(a[e] - a[s]);
}
long long dp(int l, int r, int b) {
	if (l == 1 && r == n) return 0;
	if (l < 1 || r > n) return 1e9;

	auto & ref = d[l][r][b];
	if (ref != -1) return ref;

	auto t = w[n] - w[r] + w[l - 1];
	if (b) ref = min(
		dp(l, r + 1, 1) + c(r, r + 1, t),
		dp(l - 1, r, 0) + c(r, l - 1, t));
	else ref = min(
		dp(l, r + 1, 1) + c(l, r + 1, t),
		dp(l - 1, r, 0) + c(l, l - 1, t));
	return ref;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i =1; i<=n; ++i) {
		scanf("%d%d", a + i, w + i);
		w[i] += w[i - 1];
	}
	memset(d, -1, sizeof d);
	printf("%d", dp(m, m, 0));
}
