#include <bits/stdc++.h>

using namespace std;

int n, x, y, d[100];
pair<int, int> a[100];
int dp(int x) {
	int & ref = d[x];
	if (ref != -1) return ref;
	ref = 1;
	for(int i =0; i<x; ++i) {
		if (a[i].second <= a[x].second)
			ref = max(ref, dp(i) + 1);
	}
	return ref;
}
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) cin >> x >> y, a[i] = minmax(x, y);
	sort(a, a + n);
	memset(d, -1, sizeof d);
	int ans = 0;
	for(int i =0; i<n; ++i) ans = max(ans, dp(i));
	cout << ans;
}