#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	int ans = 0, cnt = -1;
	for(char c : s) {
		if (c == '1') {
			if (cnt >= 0) ans += cnt;
			cnt = 0;
		}
		else if (cnt >= 0) cnt++;
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}