#include <bits/stdc++.h>
using namespace std;

const int c[6][6] = {
	{10,8,7,5,0,1},
	{8,6,4,3,0,1},
	{7,4,3,2,0,1},
	{5,3,2,2,0,1},
	{0,0,0,0,0,0},
	{1,1,1,1,0,0} };
int n, m, d[225][1 << 15];
char a[15][15];

int p(int i) {
	return a[i / m][i % m] - 'A';
}
int dp(int i, int mask) {
	if (i == n * m) return 0;
	if (mask & 1) return dp(i + 1, mask >> 1);
	int & ref = d[i][mask];
	if (ref != -1) return ref;
	ref = dp(i + 1, mask >> 1);
	if (i / m + 1 < n) ref = max(ref, dp(i + 1, (mask >> 1) | (1 << (m - 1))) + c[p(i)][p(i + m)]);
	if (!(mask & 2) && i % m + 1 < m) ref = max(ref, dp(i + 2, mask >> 2) + c[p(i)][p(i + 1)]);
	return ref;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(d, -1, sizeof d);
	cin >> n >> m;
	for(int i =0; i<n; ++i) cin >> a[i];
	cout << dp(0, 0);
}
