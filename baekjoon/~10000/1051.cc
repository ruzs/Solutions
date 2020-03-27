#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(auto & i : a) cin >> i;
	int ans = 1;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			for(int k =1; i+k<n && j+k<m; ++k) {
				if (a[i + k][j] == a[i][j] &&
					a[i][j + k] == a[i][j] &&
					a[i + k][j + k] == a[i][j])
					ans = max(ans, k + 1);
			}
		}
	}
	cout << ans * ans;
}