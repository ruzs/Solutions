#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = -1e9, sum = 0;
		for(int i =0, j =0; j<n; ++j) {
			int x; cin >> x;
			sum += x;
			if (ans < sum) ans = sum;
			if (sum < 0) sum = 0;
		}
		cout << ans << '\n';
	}
}