#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	pair<int, int> a[100005];

	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i].second;
	for(int i =0; i<n; ++i) cin >> a[i].first;
	sort(a, a + n);
	long long ans = 0;
	for(int i =0; i<n; ++i) {
		ans += 1LL * a[i].first * i + a[i].second;
	}
	cout << ans;
}