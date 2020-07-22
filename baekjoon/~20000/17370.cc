#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	bool v[50][50]{};
	int cnt = 0;
	function<void(int, int, int, int, int)> bt = [&](int n, int y, int x, int py, int px) {
		if (n < 0) return;
		if (v[y][x]) {
			cnt += n == 0;
			return;
		}
		v[y][x] = 1;
		if (y % 2 == x % 2) {
			if (y + 1 != py || x != px) bt(n - 1, y + 1, x, y, x);
		} else {
			if (y - 1 != py || x != px) bt(n - 1, y - 1, x, y, x);
		}
		if (y != py || x + 1 != px) bt(n - 1, y, x + 1, y, x);
		if (y != py || x - 1 != px) bt(n - 1, y, x - 1, y, x);
		v[y][x] = 0;
	};
	v[25][25] = 1;
	bt(n, 26, 25, 25, 25);
	cout << cnt;
}