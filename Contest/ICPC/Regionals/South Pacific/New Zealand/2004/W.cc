#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	char c;
	while(cin >> c) {
		if (c == '#') break;
		string s;
		getline(cin, s);
		int cnt = 0;
		for(auto i : s) if (tolower(i) == c) cnt++;
		cout << c << ' ' << cnt << '\n';
	}
}