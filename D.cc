#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, m, x;
	map<long long, int> mp;

	for(long long i = 1; i<=1LL<<60; i<<=1) mp[i] = 0;
	cin >> n >> m;
	while(m--) {
		cin >> x;
		mp[x]++;
	}
	int ans = 0, cnt = 0;
	for(auto & i : mp) {
		while (n >= i.first) {
			auto lb = mp.lower_bound(i.first);
			cnt = 0;
			while(lb != mp.end() && !lb->second) lb++, cnt++;
			if (lb == mp.end()) {
				break;
			}
			ans += cnt;
			lb->second--;
			n -= i.first;
		}
	}
	if (!n) cout << ans << '\n';
	else cout << "-1\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}