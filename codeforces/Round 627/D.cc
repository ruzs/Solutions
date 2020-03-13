#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i =0; i<n; ++i) cin >> a[i];
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		a[i] -= x;
	}
	sort(a.begin(), a.end());
	long long ans = 0;
	for(int i =0; i<n; ++i) {
		ans += n - (upper_bound(a.begin() + i + 1, a.end(), -a[i]) - a.begin());
	}
	cout << ans;
}