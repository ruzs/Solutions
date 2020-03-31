#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string a, b, c;
		cin >> a >> b >> c;
		unordered_map<char, char> mp;
		for(int i =0; i<a.size(); ++i) {
			if (i == a.size() - 1) mp[a[i]] = a[0];
			else mp[a[i]] = a[i + 1];
		}
		vector<int> ans;
		for(int i =0; i<a.size(); ++i) {
			auto KMP = [](string & s, string & t) {
				int n = s.size();
				vector<int> pi(n), r;
				for(int i =1, j =0; i<n; ++i) {
					while(j && s[i] != s[j]) j = pi[j - 1];
					if (s[i] == s[j]) pi[i] = ++j;
				}
				for(int i =0, j =0; i<t.size(); ++i) {
					while(j && t[i] != s[j]) j = pi[j - 1];
					if (t[i] == s[j] && ++j == n) r.push_back(i - n + 1);
				}
				return r;
			} (b, c);
			if (KMP.size() == 1) ans.push_back(i);
			for(char & c : b) c = mp[c];
		}
		if (ans.empty()) cout << "no solution\n";
		else if (ans.size() == 1) {
			cout << "unique: " << ans.front() << '\n';
		} else {
			cout << "ambiguous: ";
			for(int i : ans) cout << i << ' ';
			cout << '\n';
		}
	}
}