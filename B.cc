#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, a[200005];
	cin >> n;
	for(int i =0; i<n*2; ++i) cin >> a[i];
	sort(a, a + n * 2);
	int ans = 1e9;
	for(int i =0; i<n - 1; ++i) {
		ans = min(ans, a[n] - a[i]);
	}
	for(int i =n; i<n * 2; ++i) {
		ans = min(ans, a[i] - a[n - 1]);
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}