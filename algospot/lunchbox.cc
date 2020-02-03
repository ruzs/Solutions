#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m, e, ans = 0;
	pair<int, int> a[10005];
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i].second;
	for(int i =0; i<n; ++i) cin >> a[i].first;
	sort(a, a + n);
	int l = 0;
	for(int i =n-1; ~i; --i) {
		ans = max(ans, l + a[i].first + a[i].second);
		l += a[i].second;
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--) solve();
}