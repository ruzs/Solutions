#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, X, Y;
	cin >> n >> X >> Y;
	int a[1 << 7][1 << 7];
	X--; Y--;

	int num = 0;
	function<void(int, int, int, int, int)> dc = [&](int m, int y, int x, int hy, int hx) {
		if (m == 1) {
			a[y][x] = a[y][x + 1] = a[y + 1][x] = a[y + 1][x + 1] = ++num;
		} else {
			int l =1 << m - 1;
			if (hy < y + l && hx < x + l) dc(m - 1, y, x, hy, hx);
			else dc(m - 1, y, x, y + l - 1, x + l - 1);
			if (hy < y + l && hx >= x + l) dc(m - 1, y, x + l, hy, hx);
			else dc(m - 1, y, x + l, y + l - 1, x + l);
			if (hy >= y + l && hx < x + l) dc(m - 1, y + l, x, hy, hx);
			else dc(m - 1, y + l, x, y + l, x + l - 1);
			if (hy >= y + l && hx >= x + l) dc(m - 1, y + l, x + l, hy, hx);
			else dc(m - 1, y + l, x + l, y + l, x + l);
			if (hy < y + l && hx < x + l) {
				a[y + l - 1][x + l] = a[y + l][x + l - 1] = a[y + l][x + l] = ++num;
			} else if (hy < y + l) {
				a[y + l - 1][x + l - 1] = a[y + l][x + l - 1] = a[y + l][x + l] = ++num;
			} else if (hx < x + l) {
				a[y + l - 1][x + l - 1] = a[y + l - 1][x + l] = a[y + l][x + l] = ++num;
			} else {
				a[y + l - 1][x + l - 1] = a[y + l - 1][x + l] = a[y + l][x + l - 1] = ++num;
			}
		}
	};
	dc(n, 0, 0, Y, X);
	a[Y][X] = -1;
	for(int i =(1<<n)-1; ~i; --i) {
		for(int j =0; j<1<<n; ++j) cout << a[i][j] << ' ';
		cout << '\n';
	}
}