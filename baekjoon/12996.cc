#include <bits/stdc++.h>

using namespace std;

int d[51][51][51][51], m = 1e9 + 7;
int dp(int r, int a, int b, int c) {
	if (a < 0 || b < 0 || c < 0) return 0;
	if (!r) return !a && !b && !c;
	if (!a && !b && !c) return 0;

	int & ref = d[r][a][b][c];
	if (ref != -1) return ref;

	return ref = (0LL +
		dp(r - 1, a - 1, b, c) +
		dp(r - 1, a, b - 1, c) +
		dp(r - 1, a, b, c - 1) + 
		dp(r - 1, a - 1, b - 1, c) + 
		dp(r - 1, a - 1, b, c - 1) + 
		dp(r - 1, a, b - 1, c - 1) +
		dp(r - 1, a - 1, b - 1, c - 1)) % m;
}
int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	memset(d, -1, sizeof d);
	cout << dp(n, a, b, c);
}