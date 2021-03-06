#include <bits/stdc++.h>

using namespace std;

using point = complex<long long>;
long long ccw(point a, point b, point c) {
	return (conj(b - a) * (c - b)).imag();
}
bool cross(point a, point b, point c, point d) {
	return (ccw(a, c, b) ^ ccw(a, d, b)) < 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d, e, f, g, h;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	if (a > c) swap(a, c), swap(b, d);
	if (e > g) swap(e, g), swap(f, h);
	
	cout << (cross({a, b}, {c, d}, {e, f}, {g, h}) &&
			cross({e, f}, {g, h}, {a, b}, {c, d}));
}