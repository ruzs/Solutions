#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int mod = 1e9 + 9;
	int n;
	cin >> n;
	int d[33334][3];
	memset(d, -1, sizeof d);
	d[1][0] = 0;
	d[1][1] = 1;
	d[1][2] = 1;
	function<int(int, int)> dp = [&](int x, int y) {
		int & ref = d[x][y];
		if (~ref) return ref;
		ref = 0;
		for(int i =0; i<3; ++i) {
			ref = (ref + dp(x - 1, i)) % mod;
		}
		return ref;
	};
	cout << dp(n, 0);
}