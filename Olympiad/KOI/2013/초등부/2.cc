#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, w, m;
	cin >> n >> w >> m;
	map<int, int> mp;
	vector<vector<pair<int, int>>> v(n + 1);
	for(int i =0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
	}
	int s = 0, ans = 0;
	for(int i =1; i<=n; ++i) {
		if (mp[i]) {
			s -= mp[i];
			ans += mp[i];
		}
		for(auto & j : v[i]) {
			mp[j.first] += j.second;
			s += j.second;
		}
		while(s > w) {
			auto mx = prev(mp.end());
			int out = min(s - w, mx->second);
			s -= out;
			if (!(mx->second -= out)) mp.erase(mx);
		}
	}
	cout << ans;
}