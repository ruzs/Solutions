#include <bits/stdc++.h>
using namespace std;

int n, sng[20][20], d[1 << 20];
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<n; ++j) {
			cin >> sng[i][j];
		}
	}
	int all = (1 << n) - 1;
	for(int state = 1; state < all; ++state) {
		int i = 0;
		while(!(state & (1 << i))) i++;
		d[state] = d[state - (1 << i)];
		for(int j =0; j < n; ++j) {
			if (state & (1 << j)) d[state] += sng[i][j] + sng[j][i];
		}
	}
	int ans = 1e9;
	for(int state = 1; state < all; ++state) {
		ans = min(ans, abs(d[state] - d[state ^ all]));
	}
	cout << ans;
}
