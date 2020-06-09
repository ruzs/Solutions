#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), b;
	for(int i =0; i<n; ++i) {
		int x; cin >> x;
		a[x - 1] = i;
	}
	for(int i =0; i<n; ++i) {
		int x; cin >> x;
		set<int, greater<int>> c;
		for(int j =min(n, x + 4); j >= max(1, x - 4); --j) {
			c.insert(a[j - 1]);
		}
		b.insert(b.end(), c.begin(), c.end());
	}
	vector<int> d = {-1};
	for(int i : b) {
		if (d.back() < i) d.push_back(i);
		else *lower_bound(d.begin(), d.end(), i) = i;
	}
	cout << d.size() - 1;
}