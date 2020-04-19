#include <bits/stdc++.h>

using namespace std;

#define int long long

tuple<int, int, int> eea(int a, int b) {
	if (a == 0) return {b, 0, 1};
	auto [g, x, y] = eea(b % a, a);
	return {g, y - (b / a) * x, x};
}
signed main() {
	int a, b, s;
	cin >> a >> b >> s;

	if (a > b) swap(a, b);
	if (a == s || b == s) cout << "YES";
	else if (a == 0) {
		if (b == 0) {
			if (s) cout << "NO";
			else cout << "YES";
		} else {
			if (s % b) cout << "NO";
			else cout << "YES";
		}
	} else {
		int g, x, y, z;
		tie(g, x, y) = eea(a, b);
		
		if (s % g) {
			cout << "NO";
			return 0;
		}

		z = b / g;
		x = (((x % z) * ((s / g) % z)) % z + z) % z;
		y = (s - a * x) / b;

		while (y > 0) {
			if (x > 0 && __gcd(x, y) == 1) {
				cout << "YES";
				return 0;
			}
			x += b / g;
			y -= a / g;
		}
		cout << "NO";
	}
}