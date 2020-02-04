#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a[200005];
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	sort(a, a + n);
	int m = n & 1 ? a[n / 2] : (a[n / 2 - 1] + a[n / 2]) / 2;
	long long ans = 0;
	for(int i =0; i<n; ++i) ans += abs(a[i] - m);
	cout << ans;
}