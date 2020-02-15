#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	if ((y - x) % (b + a) == 0) {
		cout << (y - x) / (b + a) << '\n';
	}
	else cout << "-1\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}