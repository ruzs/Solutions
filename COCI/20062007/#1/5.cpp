#include <bits/stdc++.h>

using namespace std;

int n;
double a[20][20], d[2][1<<20];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =0; i<n; ++i) for(int j =0; j<n; ++j) {
		cin >> a[i][j];
		a[i][j] /= 100;
	}
	for(int i =0; i<n; ++i) {
		d[0][1 << i] = a[0][i];
	}
	for(int i =1, x =1; i<n; ++i, x^=1) {
		for(int s =0; s<1<<n; ++s) {
			if (__builtin_popcount(s) - 1 != i) continue;
			for(int j =0; j<n; ++j) {
				if (s & (1 << j)) d[x][s] = max(d[x][s], d[x^1][s - (1 << j)] * a[i][j]);
			}
		}
	}
	cout << setprecision(20) << d[!(n & 1)][(1 << n) - 1] * 100;
}
