#include <bits/stdc++.h>

using namespace std;

int a[9][9];
bool valid(int r, int c, int n) {
	for(int i =0; i<9; ++i) {
		if (a[r][i] == n) return 0;
		if (a[i][c] == n) return 0;
	}
	for(int i =0; i<3; ++i) {
		for(int j =0; j<3; ++j) {
			if (a[r / 3 * 3 + i][c / 3 * 3 + j] == n) return 0;
		}
	}
	return 1;
}
bool rec(int r, int c) {
	if (c == 9) return rec(r + 1, 0);
	if (r == 9) {
		for(int i =0; i<9; ++i) {
			for(int j =0; j<9; ++j) cout << a[i][j];
			cout << '\n';
		}
		return 1;
	}
	for(int i =c; i<9; ++i) {
		if (a[r][i] == 0) {
			for(int j =1; j<=9; ++j) if (valid(r, i, j)) {
				a[r][i] = j;
				if (rec(r, i + 1)) return 1;
			}
			a[r][i] = 0;
			return 0;
		}
	}
	return rec(r, c + 1);
}
int main() {
	for(int i =0; i<9; ++i)
		for(int j =0; j<9; ++j)
			scanf("%1d", &a[i][j]);
	rec(0, 0);
}