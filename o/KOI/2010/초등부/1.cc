#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, mn = 2e9;
	vector<int> p, m;
	pair<int, int> ans;
	cin >> n;
	for(int i =0, a; i<n; ++i) {
		cin >> a;
		if (a < 0) m.push_back(a);
		else p.push_back(a);
	}
	if (p.size() >= 2) {
		if (mn > abs(p[0] + p[1])) {
			mn = abs(p[0] + p[1]);
			ans = { p[0], p[1] };
		}
	}
	if (m.size() >= 2) {
		if (mn > abs(m[m.size() - 1] + m[m.size() - 2])) {
			mn = abs(m[m.size() - 1] + m[m.size() - 2]);
			ans = { m[m.size() - 2], m[m.size() - 1] };
		}
	}
	for(int i : m) {
		auto lo = lower_bound(p.begin(), p.end(), -i);
		if (lo != p.begin()) {
			if (mn > abs(*prev(lo) + i)) {
				mn = abs(*prev(lo) + i);
				ans = { i, *prev(lo) };
			}
		}
		if (lo == p.end()) continue;
		if (mn > abs(*lo + i)) {
			mn = abs(*lo + i);
			ans = { i, *lo };
		}
	}
	cout << ans.first << ' ' << ans.second;
}