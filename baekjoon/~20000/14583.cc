#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double x, y;
	cin >> x >> y;
	cout.precision(2);
	cout << fixed << x / cos(atan(y / x) / 2) / 2 << ' ' << sin(atan(y / x) / 2) * hypot(x, y);
}