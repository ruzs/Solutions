#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a, mn = 1e9, ans = 0;
	cin >> n;
	while(n--) {
		cin >> a;
		ans = max(ans, a - mn);
		if (mn > a) mn = a;
	}
	cout << ans;
}