#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a[100005]{};
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	sort(a, a + n, greater<int>());
	int mn = 1e9;
	for(int i =0; i<=n; ++i) {
		mn = min(mn, a[i] + i);
	}
	cout << mn;
}