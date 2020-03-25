#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> c(n);

	int mn = 1e9, x;
	for(int i =0; i<n; ++i) {
		cin >> c[i];
		if (mn >= c[i]) {
			mn = c[i];
			x = i;
		}
	}
	int m; cin >> m;

	string ans = "";
	while(m >= mn) {
		ans += x + '0';
		m -= mn;
	}
	while(true) {
		for(int i =0; i<ans.size(); ++i) {
			for(int j =n-1; j>x; --j) {
				if (c[ans[i] - '0'] + m >= c[j]) {
					m = c[ans[i] - '0'] + m - c[j];
					ans[i] = j + '0';
					break;
				}
			}
		}
		if (ans[0] != '0' || ans.size() == 1) break;
		ans.pop_back();
		m += c[0];
	}
	cout << ans;
}