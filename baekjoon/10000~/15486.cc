#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[1500005];
int d[1500005];
int dp(int x) {
	if (x > n) return -1e9;
	if (x == n) return 0;
	int & ref = d[x];
	if (ref != -1) return ref;
	return ref = max(dp(x + a[x].first) + a[x].second, dp(x + 1));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i].first >> a[i].second;
	memset(d, -1, sizeof d);
	cout << dp(0);
}