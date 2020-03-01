#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, l, d[32][32], p[32][32];
long long x;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> x;
	for(int i =0; i<32; ++i) d[i][0] = p[i][0] = p[0][i] = 1;
	for(int i =1; i<32; ++i) {
		for(int j =1; j<32; ++j) {
			d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
			p[i][j] = p[i][j - 1] + d[i][j];
		}
	}
	while (n--) {
		if (l > 0 && p[n][l] < x) {
			cout << 1;
			x -= p[n][l];
			l--;
		}
		else {
			cout << 0;
		}
	}
}
