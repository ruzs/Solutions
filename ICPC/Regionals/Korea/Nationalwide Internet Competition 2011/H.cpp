#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int t, c, D, d, x, dp[101][101][2][2];
vector<int> a, b;
int rec(int i, int j, int ar, int br) {
	int & ref = dp[i][j][ar][br];
	if (ref != -1) return ref;

	if (i >= a.size() && j >= b.size()) return ref = 0;
	if (i >= a.size()) return ref = rec(i, j + 1, 1, 0) + (ar ? d : D + d) + c;
	if (j >= b.size()) return ref = rec(i + 1, j, 0, 1) + (br ? d : D + d) + c;
	ref = rec(i + 1, j + 1, 0, 0) + (a[i] == b[j] ? c : 2 * c);
	ref = min(ref, rec(i, j + 1, 1, 0) + (ar ? d : D + d) + c);
	ref = min(ref, rec(i + 1, j, 0, 1) + (br ? d : D + d) + c);
	return ref;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--){
		cin >> c >> D >> d;
		a.clear();
		b.clear();
		memset(dp, -1, sizeof dp);
		for(cin >> x; x; cin >> x) a.push_back(x);
		for(cin >> x; x; cin >> x) b.push_back(x);
		cout << rec(0, 0, 0, 0) << '\n';
	}
}
