#include <bits/stdc++.h>

using namespace std;

int n, a[5];
long long D[6][6][11][11][11][11][11];

auto dp(int p, int q, int a, int b, int c, int d, int e) {
	if (!a && !b && !c && !d && !e) return 1LL;
	auto & ref = D[p][q][a][b][c][d][e];
	if (ref != -1) return ref;
	ref = 0;
	if (a && p != 1 && q != 1) ref += dp(q, 1, a - 1, b, c, d, e);
	if (b && p != 2 && q != 2) ref += dp(q, 2, a, b - 1, c, d, e);
	if (c && p != 3 && q != 3) ref += dp(q, 3, a, b, c - 1, d, e);
	if (d && p != 4 && q != 4) ref += dp(q, 4, a, b, c, d - 1, e);
	if (e && p != 5 && q != 5) ref += dp(q, 5, a, b, c, d, e - 1);
	return ref;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(D, -1, sizeof D);
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	cout << dp(0, 0, a[0], a[1], a[2], a[3], a[4]);
}
