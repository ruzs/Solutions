#include <bits/stdc++.h>

using namespace std;

bool ispalindrome(const string & s, int l, int r) {
	if (l >= r) return 1;
	if (s[l] == s[r]) return ispalindrome(s, l + 1, r - 1);
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	set<string> st;
	for(auto & i : s) cin >> i;

	string ans{}, ans1{}, ans2{};
	for(auto & i : s) {
		string t = i;
		reverse(t.begin(), t.end());
		if (st.count(i)) {
			st.erase(i);
			ans1 += i;
			ans2 = t + ans2;
		}
		else st.insert(t);
	}
	ans += ans1;
	string t = "";
	for(auto & i : st) if (ispalindrome(i, 0, m - 1)) {
		if (t.size() < i.size()) t = i;
	}
	ans += t + ans2;
	cout << ans.size() << '\n' << ans;
}