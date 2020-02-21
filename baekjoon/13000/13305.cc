#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a[100005];
	cin >> n;
	for(int i =0; i<n - 1; ++i) cin >> a[i];
	long long mn = 1e9, ans = 0, p;
	for(int i =0; i<n; ++i) {
		cin >> p;
		if (mn > p) mn = p;
		ans += mn * a[i];
	}
	cout << ans;
}