#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		set<long long > c;
		for(long long i = 1; i < 1e18; i*=k) {
			c.insert(i);
		}
		map<long long, int> mp;
		for(int i =0; i<n; ++i) {
			long long x;
			cin >> x;
			while(x) {
				auto it = prev(c.upper_bound(x));
				mp[*it] += x / *it;
				x %= *it;
			}
		}
		if (any_of(mp.begin(), mp.end(), [](auto & i) { return i.second > 1; })) cout << "NO\n";
		else cout << "YES\n";
	}
}