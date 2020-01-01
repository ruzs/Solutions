#include <bits/stdc++.h>

using namespace std;

int t, n;
string w, x;
vector<string> ans;

int d[101][101];
int dp(int i, int j) {
	int & r = d[i][j];
	if (r != -1) return r;
	while(i < w.size() && j < x.size() && (w[i] == x[j] || w[i] == '?')) i++, j++;
	if (i == w.size()) return r = (j == x.size());
	if (w[i] == '*') {
		while(j <= x.size())
			if (dp(i + 1, j++)) return r = 1;
	}
	return r = 0;
}
bool matched() {
	memset(d, -1, sizeof d);
	return dp(0, 0);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> w >> n;
		ans.clear();
		for(int i =0; i<n; ++i) {
			cin >> x;
			if (matched()) ans.push_back(x);
		}
		sort(ans.begin(), ans.end());
		for(auto & i : ans) cout << i << '\n';
	}
}
