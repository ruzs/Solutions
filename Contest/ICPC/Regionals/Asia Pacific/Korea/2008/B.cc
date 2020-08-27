#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int k;
		string s;
		cin >> k >> s;
		vector<array<int, 4>> a = {{0, 0, 0, 0}};
		for(char c : s) {
			a.push_back(a.back());
			if (c == 'A') {
				a.back()[0]++;
			} else if (c == 'G') {
				a.back()[1]++;
			} else if (c == 'C') {
				a.back()[2]++;
			} else if (c == 'T') {
				a.back()[3]++;
			}
		}
		int ans = 0;
		const int mod = 1e9 + 7;
		unordered_map<int, int> mp;
		for(int i =k; i<=s.size(); ++i) {
			long long hash = 0;
			for(int j =0; j<4; ++j) {
				hash = (hash * 53 + a[i][j] - a[i - k][j]) % mod;
			}
			ans = max(ans, ++mp[hash]);
		}
		cout << ans << '\n';
	}
}