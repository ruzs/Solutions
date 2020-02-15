#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while(cin >> s) {
		if (s == "0") break;
		auto x = find(s.begin() + 1, s.end(), '1');
		do {
			cout << x - s.begin() << ' ';
			for(int i =0; i<s.size(); i += x - s.begin()) s[i] ^= 1;
			x = find(s.begin() + 1, s.end(), '1');
		} while(x != s.end());
		cout << '\n';
	}
}