#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, p, e, x[20], y[20];
	cin >> n >> p >> e;
	for(int i =0; i<n; ++i) cin >> x[i] >> y[i];
	for(int s =0; s<1<<n; ++s) {
		if (__builtin_popcount(s) != p) continue;
		int mn = 0, mx = 0;
		for(int i =0; i<n; ++i) if (s & 1 << i) {
			mn += x[i]; mx += y[i];
		}
		if (mn <= e && e <= mx) {
			int ans[20]{};
			for(int i =0; i<n; ++i) if (s & 1 << i) {
				ans[i] += x[i];
				e -= x[i];
			}
			for(int i =0; i<n; ++i) if (s & 1 << i) {
				int d = min(y[i] - ans[i], e);
				e -= d;
				ans[i] += d;
			}
			for(int i =0; i<n; ++i) {
				cout << ans[i] << ' ';
			}
			return 0;
		}
	}
	cout << -1;
}