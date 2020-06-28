#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	map<char, int> mp;
	for(char c : s) mp[c]++;
	for(char i : {'3', '4', '5', '6', '7', '9'}) if (mp.count(i)) {
		cout << "0";
		return 0;
	}
	if (mp.size() != 4) {
		cout << "1";
	} else if (mp['2'] != mp['1'] || mp['2'] != mp['0'] || mp['2'] != mp['8']) {
		cout << "2";
	} else {
		cout << "8";
	}
}