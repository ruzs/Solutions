#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int a[501][501], sum = 0;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			string s;
			cin >> s;
			int cnt = 0;
			for(char c : s) {
				if (c == '9') cnt++;
			}
			a[i][j] = cnt;
			sum += cnt;
		}
	}
	int mx = 0;
	for(int i =0; i<n; ++i) {
		int cnt = 0;
		for(int j =0; j<m; ++j) cnt += a[i][j];
		mx = max(mx, cnt);
	}
	for(int j =0; j<m; ++j) {
		int cnt = 0;
		for(int i =0; i<n; ++i) cnt += a[i][j];
		mx = max(mx, cnt);
	}
	cout << sum - mx;
}