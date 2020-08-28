#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	int q;
	cin >> s >> q;
	vector<vector<int>> p(26, {0});
	for(char c : s) {
		for(int i =0; i<26; ++i)
			p[i].push_back(p[i].back());
		p[c - 'a'].back()++;
	}
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vector<int> x(26), y(26);
		for(int i =0; i<26; ++i) {
			x[i] = p[i][b] - p[i][a - 1];
			y[i] = p[i][d] - p[i][c - 1];
		}
		if (x == y) cout << "DA\n";
		else cout << "NE\n";
	}
}