#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	vector<string> a(n);
	for(string & i : a) cin >> i;
	vector<vector<int>> d(n + 1, vector<int>(m + 1));
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			d[i + 1][j + 1] = d[i + 1][j] + d[i][j + 1] - d[i][j] + (a[i][j] == '*');
		}
	}
	int py, px, mx = -1, cnt = 0;
	for(int i =1; i+k-1<=n; ++i) {
		for(int j =1; j+k-1<=m; ++j) {
			cnt = d[i+k-2][j+k-2] - d[i][j+k-2] - d[i+k-2][j] + d[i][j];
			if (mx < cnt) {
				mx = cnt;
				py = i-1;
				px = j-1;
			}
		}
	}
	a[py][px] = '+';
	a[py][px+k-1] = '+';
	a[py+k-1][px] = '+';
	a[py+k-1][px+k-1] = '+';
	for(int i =1; i<k-1; ++i) {
		a[py][px + i] = '-';
		a[py+k-1][px + i] = '-';
		a[py + i][px] = '|';
		a[py + i][px+k-1] = '|';
	}
	cout << mx << '\n';
	for(int i =0; i<n; ++i) {
		cout << a[i] << '\n';
	}
}