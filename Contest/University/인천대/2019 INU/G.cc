#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	cin >> n >> t;
	vector<pair<int, int>> a(n);
	for(auto & i : a) cin >> i.first >> i.second;
	sort(a.begin(), a.end(), [](auto a, auto b) {
		return a.second > b.second;
	});
	long long ans = 0;
	for(int i =0; i<n; ++i) {
		ans += 1ll * (t - i - 1) * a[i].second + a[i].first;
	}
	cout << ans;
}