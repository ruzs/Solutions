#include <bits/stdc++.h>

using namespace std;

string a, b;
int d[1001][1001][2];
int dp(int i, int j, int k) {
	if (i == a.size() && j == b.size()) return 0;
	if (i == a.size()) return 1;
	if (j == b.size()) return 1e9;
	int & ref = d[i][j][k];
	if (ref != -1) return ref;
	ref = 1e9;
	if (a[i] == b[j]) ref = min(ref, dp(i + 1, j + 1, 1));
	return ref = min(ref, dp(i, j + 1, 0) + k);
}
int main() {
	getline(cin, a);
	getline(cin, b);
	memset(d, -1, sizeof d);
	int ans = dp(0, 0, 1);
	cout << (ans < 1e9 ? ans : -1);
}