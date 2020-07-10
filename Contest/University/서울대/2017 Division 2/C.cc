#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	vector<string> a(n, string(n, '.'));
	vector<vector<int>> c(n, vector<int>(n));
	a[0] = s;
	for(int i =1; i<n; ++i) {
		for(int j =0; j<n; ++j) {
			if (j > 0 && a[i - 1][j - 1] == '#') c[i - 1][j]++;
			if (j < n - 1 && a[i - 1][j + 1] == '#') c[i - 1][j]++;
		}
		for(int j =0; j<n; ++j) {
			if (c[i - 1][j] & 1) a[i][j] = '#';
			if (a[i - 1][j] == '#') c[i][j]++;
		}
	}
	for(int i =0; i<n; ++i) cout << a[i] << '\n';
}