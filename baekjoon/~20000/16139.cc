#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	int q;
	cin >> s >> q;
	vector<vector<int>> p(26, {0});
	for(int i =0; i<s.size(); ++i) {
		for(int j =0; j<26; ++j) {
			p[j].push_back(p[j].back());
		}
		p[s[i] - 'a'].back()++;
	}
	while (q--) {
		char c;
		int s, e;
		cin >> c >> s >> e;
		cout << p[c - 'a'][e + 1] - p[c - 'a'][s] << '\n';
	}
}