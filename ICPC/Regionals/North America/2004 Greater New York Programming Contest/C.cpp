#include <bits/stdc++.h>

using namespace std;

int t, n, m;
long long d[11][2001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i =0; i<=2000; ++i) d[0][i] = 1;
	for(int i =1; i<=10; ++i) {
		for(int j =1; j<=2000; ++j) {
			d[i][j] = d[i - 1][j >> 1] + d[i][j - 1];
		}
	}
	cin >> t;
	while(t--) {
		cin >> n >> m;
		cout << d[n][m] << '\n';
	}
}
