#include <bits/stdc++.h>

using namespace std;

int n, m, k, l, a, b, f[12], s[10], d[10][1 << 12];

int dp(int c, int msk) {
	if (__builtin_popcount(msk) >= m) return 0;
	if (c == k) return 1e9;

	int& ref = d[c][msk];
	if (~ref) return ref;

	ref = dp(c + 1, msk);
	for(int i =1; i<1<<n; ++i) {
		if ((msk & i) || ((s[c] & i) != i)) continue;
		if (__builtin_popcount(i) > l) continue;
		bool ok = 1;
		for(int j =0; j<n; ++j) {
			if ((i & (1 << j)) && ((f[j] & msk) != f[j])) ok = 0;
		}
		if (ok) ref = min(ref, dp(c + 1, msk | i) + 1);
	}
	return ref;
}
void solve() {
	memset(f, 0, sizeof f);
	memset(s, 0, sizeof s);

	cin >> n >> m >> k >> l;
	for(int i =0; i<n; ++i) {
		cin >> a;
		while(a--) {
			cin >> b;
			f[i] |= 1<<b;
		}
	}
	for(int i =0; i<k; ++i) {
		cin >> a;
		while(a--) {
			cin >> b;
			s[i] |= 1<<b;
		}
	}
	memset(d, -1, sizeof d);
	int r = dp(0, 0);
	if (r < 1e9) cout << r << '\n';
	else cout << "IMPOSSIBLE\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}