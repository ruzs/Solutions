#include <bits/stdc++.h>
using namespace std;

const int M = 835454957;
map<string, vector<string>> pre, suf;
map<tuple<int, int, string>, int> d;
set<string> st;

bool isPalindrome(const string &s, int l, int r) {
	if (l >= r) return 1;
	return s[l] == s[r] ? isPalindrome(s, l + 1, r - 1) : 0;
}
int dp(int n, int prefix, string fix) {
	if (n == -1) return isPalindrome(fix, 0, fix.size() - 1);
	if (n <= 0) return 0;
	auto f = d.find({n, prefix, fix});
	if (f != d.end()) return f->second;
	
	int res = 0;
	if (prefix) {
		for(auto & i : pre[fix]) {
			if (i.size() > n) continue;
			auto r = i.substr(fix.size(), i.size() - fix.size());
			reverse(r.begin(), r.end());
			res = (res + dp(n - i.size() - 1, 0, r)) % M;
		}
		string t = "";
		for(int i =0; i<(int)fix.size() - 1; ++i) {
			t += fix[i];
			if (st.count(t)) res = (res + dp(n - t.size() - 1, 1, fix.substr(i + 1, fix.size() - i - 1))) % M;
		}
	} else {
		for(auto & i : suf[fix]) {
			if (i.size() > n) continue;
			auto r = i.substr(0, i.size() - fix.size());
			reverse(r.begin(), r.end());
			res = (res + dp(n - i.size() - 1, 1, r)) % M;
		}
		string t = "", r = fix;
		for(int i =0; i<(int)fix.size() - 1; ++i) {
			t = r.back() + t; r.pop_back();
			if (st.count(t)) res = (res + dp(n - t.size() - 1, 0, r)) % M;
		}
	}
	return d[{n, prefix, fix}] = res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;
	for(int i =0; i<n; ++i) {
		string s; cin >> s;
		string t = "";
		st.insert(s);
		pre[t].push_back(s);
		suf[t].push_back(s);
		for(char c : s) {
			t += c;
			pre[t].push_back(s);
		}
		t = "";
		for(int i =s.size() - 1; ~i; --i){
			t = s[i] + t;
			suf[t].push_back(s);
		}
	}
	int ans = 0;
	for(int i =1; i<=k; ++i) ans = (ans + dp(i, 1, "")) % M;
	cout << ans;
}
