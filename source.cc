#include <bits/stdc++.h>

using namespace std;

using point = complex<double>;
#define X real()
#define Y imag()

int ccw(point a, point b, point c) {
	long long r = (conj(b - a) * (c - b)).Y;
	return r ? r < 0 ? -1 : 1 : 0;
}
bool cross(point a, point b, point c, point d) {
	return ccw(a, c, b) * ccw(a, d, b) <= 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
}