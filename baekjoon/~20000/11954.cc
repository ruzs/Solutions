#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int st = 0;
	vector<string> ans;
	string word;
	for(char c : s) {
		if (c == '{') ans.push_back(string(st++ * 2, ' ') + '{');
		else if (c == '}') {
			if (word != "") ans.push_back(string(st * 2, ' ') + word), word = "";
			ans.push_back(string(--st * 2, ' ') + '}');
		}
		else if (c == ',') {
			if (word == "") ans.back() += ',';
			else ans.push_back(string(st * 2, ' ') + word + ','), word = "";
		}
		else word += c;
	}
	for(auto & i : ans) cout << i << '\n';
}