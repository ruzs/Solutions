#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, r, c;
	cin >> n >> m >> r >> c;
	vector<string> s(n);
	for(string & i : s) cin >> i;
	for(int i =0; i<n; ++i) {
		for(int ii = 0; ii<r; ++ii) {
			for(int j =0; j<m; ++j) {
				for(int jj = 0; jj<c; ++jj) {
					cout << s[i][j];
				}
			}
			cout << '\n';
		}
	}
}