#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i =0; i<n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	int cnt = 0;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<i; ++j) {
			auto lb = lower_bound(a.begin(), a.end(), a[i] + (a[i] - a[j]));
			auto ub = upper_bound(a.begin(), a.end(), a[i] + (a[i] - a[j]) * 2);
			cnt += ub - lb;
		}
	}
	cout << cnt;
}