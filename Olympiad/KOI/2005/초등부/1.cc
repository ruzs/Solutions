#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<array<int, 5>> a(n);
	int mx, ans;
	for(int i =0; i<n; ++i) {
		int x = 0;
		for(int j =0; j<5; ++j) {
			cin >> a[i][j];
		}
		for(int j =0; j<5; ++j) {
			for(int k =0; k<j; ++k) {
				for(int l =0; l<k; ++l) {
					x = max(x, (a[i][j] + a[i][k] + a[i][l]) % 10);
				}
			}
		}
		if (mx <= x) {
			mx = x, ans = i + 1;
		}
	}
	cout << ans;
}