#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if (n == 1) cout << "-1\n";
		else {
			auto ans = string(n - 1, '2') + "3";
			if ((n - 1) * 2 % 3 == 0) ans[0] = '4';
			cout << ans << '\n';
		}
	}
}