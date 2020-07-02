#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int x, y;
	int a[4][4]{};
	cin >> n >> x >> y;
	if (n == 1) {
		for(int i =1; i<=2; ++i) {
			for(int j =1; j<=2; ++j) {
				if (3 - y == i && j == x) cout << -1 << ' ';
				else cout << 1 << ' ';
			}
			cout << '\n';
		}
	} else {
		a[0][0] = a[0][1] = a[1][0] = a[1][1] = 1;
		a[0][2] = a[0][3] = a[1][2] = a[1][3] = 2;
		a[2][0] = a[2][1] = a[3][0] = a[3][1] = 3;
		a[2][2] = a[2][3] = a[3][2] = a[3][3] = 4;
		a[y - 1][x - 1] = -1;
		if (y <= 2 && x <= 2) {
			a[1][2] = a[2][1] = a[2][2] = 5;
		} else if (y <= 2) {
			a[1][1] = a[2][1] = a[2][2] = 5;
		} else if (x <= 2) {
			a[1][1] = a[1][2] = a[2][2] = 5;
		} else {
			a[1][1] = a[1][2] = a[2][1] = 5;
		}
		for(int i =3; ~i; --i) {
			for(int j =0; j<4; ++j) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}