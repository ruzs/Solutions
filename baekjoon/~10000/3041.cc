#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans = 0;
	char s[5];
	for(int i =0; i<4; ++i) {
		cin >> s;
		for(int j =0; j<4; ++j) {
			if (s[j] == '.') continue;
			ans += abs((s[j] - 'A') / 4 - i);
			ans += abs((s[j] - 'A') % 4 - j);
		}
	}
	cout << ans;
}