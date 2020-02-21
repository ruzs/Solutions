#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x, a[100005];
	cin >> n >> x;
	for(int i =0; i<n; ++i) cin >> a[i];
	sort(a, a + n);
	int mxd = 1;
	for(int i =0; i<n; ++i) {
		if (x == a[i]) return cout << "1\n", void();
		if (x % a[i] == 0) mxd = max(mxd, a[i]);
	}
	if (a[n - 1] > x) cout << "2\n";
	else cout << min(x / mxd, x / a[n-1] + (lower_bound(a, a + n, x % a[n-1]) == a + n ? 2 : 1)) << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}