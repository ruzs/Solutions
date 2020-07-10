#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore();
	map<string, pair<int, int>> mp;
	vector<int> c(n);
	for(int k =0; k<n; ++k) {
		string s;
		getline(cin, s);
		int cnt = 0, i =0, j =0;
		for(; j<s.size(); ++j) {
			if (s[j] == ' ') {
				mp[s.substr(i, j - i)] = {k, cnt++};
				i = j + 1;
			}
		}
		mp[s.substr(i)] = {k, cnt++};
		c[k] = cnt;
	}
	string s;
	vector<int> l(n, 0);
	while(cin >> s) {
		if (!mp.count(s)) {
			cout << "Impossible";
			return 0;
		}
		auto p = mp[s];
		if (l[p.first] != p.second) {
			cout << "Impossible";
			return 0;
		}
		l[p.first] = p.second + 1;
	}
	if (c == l) cout << "Possible";
	else cout << "Impossible";
}