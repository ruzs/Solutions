#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int d[2][101][101];
int dp(int f, int a, int b) {
	if (!a && !b) return 1;
	if (a < 0 || b < 0) return 0;
	int & ref = d[f][a][b];
	if (ref != -1) return ref;
	ref = dp(1, a - 1, b) + dp(0, a, b - 1);
	if (ref > 1e9) ref = 1e9 + 1;
	return ref;
}
void solve() {
	cin >> n >> m >> k;
	while(n || m) {
		if (!n) cout << 'o', m--;
		else if (!m) cout << '-', n--;
		else if (dp(1, n - 1, m) >= k) cout << '-', n--;
		else cout << 'o', k -= dp(1, n - 1, m), m--;
	}
	cout << '\n';
}
int main() {
	memset(d, -1, sizeof d);
	int T; cin >> T;
	while(T--) solve();
}
