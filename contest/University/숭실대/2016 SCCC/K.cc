#include <bits/stdc++.h>

using namespace std;

const int m = 1e9 + 7;

vector<int> g[8] = {{1,2},{0,2,3},{0,1,3,4},{1,2,4,5},{2,3,5,7},{3,4,6},{5,7},{4,6}};
int d[8][100001];
int dp(int a, int r) {
	if (!r) return !a;
	int & ref = d[a][r];
	if (ref != -1) return ref;
	ref = 0;
	for(int b : g[a]) {
		ref += dp(b, r - 1);
		ref %= m;
	}
	return ref;
}
int main() {
	int n; cin >> n;
	memset(d, -1, sizeof d);
	cout << dp(0, n);
}