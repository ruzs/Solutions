#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	sort(a.begin(), a.end());
	long long ans = 0;
	for(int i =0; i<n; ++i) {
		ans += abs(i + 1 - a[i]);
	}
	cout << ans;
}