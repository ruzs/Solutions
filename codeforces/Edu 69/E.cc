#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;
int n, d[200005];
pair<int, int> a[200005];
int dp(int x) {
	int & ref = d[x];
	if (~ref) return ref;
	ref = 0;
	auto range = equal_range(a, a + n, pair<int, int>{a[x].second, 0}, [](auto& i, auto& j) {
		return i.first < j.first;
	});
	for(int i =range.first-a; i<range.second-a; ++i) {
		ref += dp(i);
		ref %= mod;
	}
	return ref += (upper_bound(a, a + n, pair<int, int>{a[x].second, 0}) == a + n);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i].second >> a[i].first;
	sort(a, a + n);

	memset(d, -1, sizeof d);
	int ans = 0;
	for(int i =0; i<n; ++i) {
		if (a[i].first != a[0].first) {
			for(int j =0; j<i; ++j)
				if (a[j].second <= a[i].first) goto L1;
		}
		ans += dp(i), ans %= mod;
	}
	L1:
	cout << ans;
}