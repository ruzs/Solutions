#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	bool k = 1;
	sort(s.begin(), s.end());
	for(int i =1; i<s.size(); ++i) {
		if (s[i - 1] == s[i]) k = 0;
	}
	if (k && s.back() - s.front() == s.size() - 1) cout << "Yes\n";
	else cout << "No\n";
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}