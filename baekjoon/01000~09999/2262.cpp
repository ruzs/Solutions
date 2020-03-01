#include <bits/stdc++.h>
using namespace std;

int n, a[260], d[260][260], w[260][260];

int dp(int l, int r) {
	if (l == r) return 0;
	int & ref = d[l][r];
	if (ref != -1) return ref;
	ref = 1e9;
	for(int i =l; i<r; ++i) {
		ref = min(ref, dp(l, i) + dp(i + 1, r) + 
		abs(w[l][i] - w[i + 1][r]));
	}
	return ref;
}
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	for(int i =0; i<n; ++i) {
		w[i][i] = a[i];
		for(int j =i + 1; j<n; ++j) {
			w[i][j] = min(w[i][j - 1], a[j]);
		}
	}
	memset(d, -1, sizeof d);
	cout << dp(0, n - 1);
}
