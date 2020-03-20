#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	cout << 1ll * (2 * n - k + 1) * k / 2 << ' ';
	long long ans = 1;
	int l = -1;
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		if (x >= n - k + 1) {
			if (~l) {
				ans *= i - l;
				ans %= 998244353;
			}
			l = i;
		}
	}
	cout << ans;
}