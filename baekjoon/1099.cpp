#include <bits/stdc++.h>

using namespace std;
using ab = vector<int>;
int n, d[51];
string l, s;
map<ab, vector<string>> mp;

ab getab(const string & a) {
	ab r(26, 0);
	for(char c : a) r[c - 'a']++;
	return r;
}
int score(const string & a, const string & b) {
	int r = 0;
	for(int i =0; i<a.size(); ++i) if (a[i] != b[i]) r++;
	return r;
}
int dp(int x) {
	if (x == l.size()) return 0;
	int & ref = d[x];
	if (ref != -1) return ref;

	string s = "";
	ab t(26, 0);
	ref = 1e9;
	for(int i =0; x + i<l.size(); ++i) {
		s += l[x + i];
		t[l[x + i] - 'a']++;
		if (mp.count(t)) {
			for(auto & j : mp[t]) {
				ref = min(ref, dp(x + i + 1) + score(s, j));
			}
		}
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(d, -1, sizeof d);
	cin >> l >> n;
	for(int i =0; i<n; ++i) {
		cin >> s;
		mp[getab(s)].push_back(s);
	}
	int ans = dp(0);
	if (ans < 1e9) cout << ans;
	else cout << -1;
}
