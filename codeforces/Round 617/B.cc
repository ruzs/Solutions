#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int ans = n;
	do {
		int m = n / 10;
		ans += m;
		n = n % 10 + m;
	} while(n >= 10);
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}