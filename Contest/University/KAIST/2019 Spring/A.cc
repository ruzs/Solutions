#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s;
	cin >> n >> s;
	int ans = 1, cnt = 0;
	for(int i =0; i<n; ++i) {
		if (s[i] == 'V') {
			cnt = 0;
		} else if (i == 0) {
			cnt = 1;
		} else if (s[i] != s[i - 1]) {
			ans = max(ans, ++cnt);
		} else {
			cnt = 1;
		}
	}
	cout << ans;
}