#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int mx = 0, cnt = 0;
		for(char c : s) {
			if (c == 'L') cnt++;
			else mx = max(mx, ++cnt), cnt = 0;
		}
		cout << max(mx, ++cnt) << '\n';
	}
}