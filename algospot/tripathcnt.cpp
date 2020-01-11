#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int a[101][101]{}, d[101][101]{};
	for(int i =0; i<=n; ++i) for(int j =1; j<=i; ++j) cin >> a[i][j];
	for(int i =1; i<=n; ++i) d[n][i] = 1;
	for(int i =n - 1; i; --i) {
		for(int j =1; j<=i; ++j) {
			if (a[i + 1][j + 1] < a[i + 1][j]) {
				a[i][j] += a[i + 1][j];
				d[i][j] = d[i + 1][j];
			}
			else if (a[i + 1][j + 1] > a[i + 1][j]) {
				a[i][j] += a[i + 1][j + 1];
				d[i][j] = d[i + 1][j + 1];
			}
			else {
				a[i][j] += a[i + 1][j];
				d[i][j] = d[i + 1][j + 1] + d[i + 1][j];
			}
		}
	}
	cout << d[1][1] << '\n';
}
int main() {
	int n; cin >> n;
	while(n--) solve();
}
