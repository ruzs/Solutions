#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x, y;
	cin >> n >> m;
	x = m; y = m;
	double mn = 1e9, r = 1.0 * n / m;
	for(int i = 32767; i; --i) {
		for(int k =0; k<5; ++k) {
			int j = n * i / m + k;
			int g = __gcd(i, j);
			if (j > i || n == j / g && m == i / g) continue;
			if (mn >= fabs(r - 1.0 * j / i)) {
				mn = fabs(r - 1.0 * j / i);
				x = j;
				y = i;
			}
			j = n * i / m - k;
			g = __gcd(i, j);
			if (j < 0 || n == j / g && m == i / g) continue;
			if (mn >= fabs(r - 1.0 * j / i)) {
				mn = fabs(r - 1.0 * j / i);
				x = j;
				y = i;
			}
		}
	}
	int g = __gcd(x, y);
	cout << x / g << ' ' << y / g;
}