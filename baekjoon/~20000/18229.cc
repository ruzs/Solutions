#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			cin >> a[i][j];
		}
	}
	vector<int> sum(n);
	for(int j =0; j<m; ++j) {
		for(int i =0; i<n; ++i) {
			sum[i] += a[i][j];
			if (sum[i] >= k) {
				cout << i + 1 << ' ' << j + 1;
				return 0;
			}
		}
	}
}