#include <bits/stdc++.h>

using namespace std;

int n, m, a[1001], d[1001][1001];
int dp(int x, int r) {
	if (x == n) return 0;
	int & ref = d[x][r];
	if (ref != -1) return ref;
	ref = dp(x + 1, m - a[x]) + r * r;
	if (a[x] < r) ref = min(ref, dp(x + 1, r - a[x] - 1));
	return ref;
}
int main() {
	cin >> n >> m;
	for(int i =0; i<n; ++i) cin >> a[i];
	memset(d, -1, sizeof d);
	cout << dp(1, m - a[0]);
}