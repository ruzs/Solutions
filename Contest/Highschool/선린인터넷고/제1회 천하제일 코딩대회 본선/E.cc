#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int & i : a) cin >> i;
	for(int & i : b) cin >> i;
	int as = 0, bs = 0, ans = 0;
	for(int i =0; i<n; ++i) {
		if (a[i] == 1 && b[i] == 3) {
			as++;
			bs = 0;
		} else if (a[i] == 3 && b[i] == 1) {
			bs++;
			as = 0;
		} else if (a[i] == b[i]) {
			if (as) as = 0, bs = 1;
			else bs = 0, as = 1;
		} else if (a[i] > b[i]) {
			as++;
			bs = 0;
		} else {
			bs++;
			as = 0;
		}
		ans = max({ans, as, bs});
	}
	cout << ans;
}