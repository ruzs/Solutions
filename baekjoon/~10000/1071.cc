#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	map<int, int> mp;
	for(int i =0; i<n; ++i) {
		int a; cin >> a;
		mp[a]++;
	}
	vector<pair<int, int>> a(mp.begin(), mp.end());
	for(int i =1; i<a.size(); ++i) {
		if (a[i - 1].first + 1 == a[i].first) {
			if (i + 1 < a.size()) {
				a.insert(a.begin() + i, {a[i + 1].first, 1});
				if (!--a[i + 2].second) a.erase(a.begin() + i + 2);
			}
			else swap(a[i - 1], a[i]);
		}
	}
	for(auto & i : a) {
		while(i.second--) cout << i.first << ' ';
	}
}