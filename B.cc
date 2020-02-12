#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, g, b;
	cin >> n >> g >> b;
	if (n <= g) cout << n << '\n';
	else {
		cout << (n + 1) / 2 / g * (g + b) + (n + 1) / 2 % g - b << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}