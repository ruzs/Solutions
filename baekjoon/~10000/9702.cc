#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, tc = 0; cin >> t;
	while (t--) [&tc] {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int & i : a) cin >> i;
		vector<int> d;
		int sum = 0;
		for(int i =0; i<n; ++i) {
			d = {-1};
			for(int j =i; j<n; ++j) {
				if (d.back() < a[j]) d.push_back(a[j]);
				else *lower_bound(d.begin(), d.end(), a[j]) = a[j];
				sum += d.size() - 1;
			}
		}
		cout << "Case #" << ++tc << ": " << sum << '\n';
	} ();
}