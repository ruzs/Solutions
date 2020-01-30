#include <bits/stdc++.h>

using namespace std;

int d[61][61][61];
int dp(int a, int b, int c) {
	if (a <= 0 && b <= 0 && c <= 0) return 0;
	if (a < 0) a = 0;
	if (b < 0) b = 0;
	if (c < 0) c = 0;
	int & ref = d[a][b][c];
	if (ref != -1) return ref;

	return ref = min({ dp(a - 9, b - 3, c - 1), dp(a - 9, b - 1, c - 3),
						dp(a - 3, b - 9, c - 1), dp(a - 3, b - 1, c - 9),
						dp(a - 1, b - 9, c - 3), dp(a - 1, b - 3, c - 9) }) + 1;
}
int main() {
	int n, a[3]{};
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	memset(d, -1, sizeof d);
	cout << dp(a[0], a[1], a[2]);
}