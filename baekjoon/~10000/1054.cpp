#include <bits/stdc++.h>
using namespace std;

int n;
string word[13];
set<string> st[2][13];
map<tuple<int, int, string>, long long> d;

bool isPalindrome(const string & s, int l, int r) {
	return l >= r ? 1 : s[l] == s[r] ? isPalindrome(s, l + 1, r - 1) : 0;
}
long long dp(int w, int s, string fix) {
	if (d.count({w, s, fix})) return d[{w, s, fix}];

	long long res =s && isPalindrome(fix, 0, fix.size() - 1);
	for(int i =0; i<n; ++i) {
		if (s & (1 << i)) continue;
		auto& r = word[i];
		if (st[w][i].count(fix)) {
			auto t = r.substr(w * fix.size(), r.size() - fix.size());
			reverse(t.begin(), t.end());
			res += dp(!w, s | (1 << i), t);
		}
		else if (fix.size() > r.size()) {
			if (fix.substr(w ? 0 : fix.size() - r.size(), r.size()) == r) {
				res += dp(w, s | (1 << i), fix.substr(w * r.size(), fix.size() - r.size()));
			}
		}
	}
	return d[{w, s, fix}] = res;
}
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> word[i];
		string t = "";
		st[1][i].insert(t);
		st[0][i].insert(t);
		for(char c : word[i]) {
			t += c;
			st[1][i].insert(t);
		}
		t = "";
		for(int j = (int)word[i].size() - 1; j>=0; --j) {
			t = word[i][j] + t;
			st[0][i].insert(t);
		}
	}
	cout << dp(0, 0, "");
}
