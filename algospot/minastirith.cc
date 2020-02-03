#include <bits/stdc++.h>

using namespace std;

const double PI = acos(0) * 2.0;

void solve() {
	int n, one = 0;
	pair<double, double> a[100];
	cin >> n;
	for(int i =0; i<n; ++i) {
		double y, x, r;
		cin >> y >> x >> r;
		x = fmod(PI * 2 + atan2(y, x), PI * 2);
		r = r >= 16 ? PI : acos(1.0 * (128 - r * r) / 128);
		a[i] = {x - r, x + r};
	}
	sort(a, a + n);
	
	int ans =1e9;
	for(int i =0; i<n; ++i) {
		if (a[i].first <= 0 || a[i].second >= PI * 2) {
			double begin = fmod(a[i].second, PI * 2);
			double end = fmod(a[i].first + PI * 2, PI * 2);
			int cnt = 1;
			while(begin < end) {
				double l = -1;
				for(int j =0; j<n; ++j) if (a[j].first <= begin) {
					l = max(l, a[j].second);
				}
				if (l <= begin) {
					cnt = 1e9;
					break;
				}
				begin = l;
				cnt++;
			}
			ans = min(ans, cnt);
		}
	}
	if (ans < 1e9) cout << ans << '\n';
	else cout << "IMPOSSIBLE\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--) solve();
}