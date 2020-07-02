#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n % 9) cout << "-1\n";
		else {
			string ans = "";
			bool f = 0;
			for(string i = "999999999"; i.size() > 0; i.pop_back()) {
				int j = stoi(i);
				if (n / j >= 10) {
					cout << "-1\n";
					f = 1;
					break;
				}
				ans += '0' + (char)(n / j);
				n %= j;
			}
			if (f) continue;
			ans += '0';
			for(int i =0; i<ans.size(); ++i) {
				if (ans[i] != '0') {
					cout << ans.substr(i) << ' ';
					break;
				}
			}
		}
	}
}