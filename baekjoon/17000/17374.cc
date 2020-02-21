#include <bits/stdc++.h>

using namespace std;

void solve() {
	int p, q, r, a, b, c, d;
	cin >> p >> q >> a >> b >> c >> d;
	r = q / c * d;
	int k = (r - p) / (a + b);
	int ans = 0;
	for(int i =k - 5000; i < k + 5000; ++i) {
		ans = max(ans, min(p + a * i, r - b * i));
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}