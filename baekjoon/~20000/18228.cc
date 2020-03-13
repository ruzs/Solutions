#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0, mn = 1e9;
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		if (x < 0) {
			ans += mn;
			mn = 1e9;
		}
		else if (mn > x) mn = x;
	}
	cout << ans + mn;
}