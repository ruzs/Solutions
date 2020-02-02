#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long y, x;
	cin >> y >> x;
	if (y < x) {
		cout << x * x - x + 1 + (x & 1 ? x - y : y - x) << '\n';
	}
	else {
		cout << y * y - y + 1 + (y & 1 ? x - y : y - x) << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	while(T--) solve();
}