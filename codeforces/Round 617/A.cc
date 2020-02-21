#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, a, s = 0, o = 0, e = 0;
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a, s += a, o |= a & 1, e |= !(a & 1);
	if (s & 1 || o && e) cout << "YES\n";
	else cout << "NO\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}