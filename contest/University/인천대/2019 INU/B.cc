#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, a[100][100], b[100]{};
	cin >> n >> m >> k;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			cin >> a[i][j];
		}
	}
	for(int j =0; j<m; ++j) {
		for(int i =0; i<n; ++i) {
			b[i] += a[i][j];
			if (b[i] >= k) {
				cout << i + 1 << ' ' << j + 1;
				return 0;
			}
		}
	}
}