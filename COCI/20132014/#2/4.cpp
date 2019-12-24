#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, d[1501][1501], c[1501][1501];
int dp(int l, int r) {
	if (l == n || r == n) return 0;
	int & ref = d[l][r];
	if (ref) return ref;

	int nxt = max(l, r) + 1;
	return ref = min(dp(nxt, r) + c[nxt][l], dp(l, nxt) + c[r][nxt]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<n; ++j) {
			cin >> c[i][j];
		}
	}
	cout << dp(0, 0);
}
