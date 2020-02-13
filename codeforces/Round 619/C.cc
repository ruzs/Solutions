#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, k;
	cin >> n >> k;
	long long all = n * (n + 1) / 2;
	if (n / 2 <= k) cout << all - (n - k) << '\n';
	else {
		long long q = (n - k) / (k + 1);
		all -= (q * (q + 1) / 2) * (k + 1);
		all -= (q + 1) * ((n - k) % (k + 1));
		cout << all << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}