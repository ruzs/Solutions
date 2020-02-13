#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s, t, p;
	cin >> s >> t >> p;
	int cnt[26]{};
	for(char c : p) cnt[c - 'a']++;
	int j = 0;
	for(int i =0; i<s.size(); ++i) {
		while (j < t.size() && s[i] != t[j]) {
			if (cnt[t[j]]) {
				cnt[t[j++]]--;
			}
			else {
				cout << "NO\n";
				return;
			}
		}
		if (j >= t.size()) {
			cout << "NO\n";
			return;
		}
		if (s[i] == t[j]) j++;
	}
	while (j < t.size()) {
		if (cnt[t[j]]) {
			cnt[t[j++]]--;
		}
		else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}