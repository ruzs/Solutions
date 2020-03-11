#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	long long ans = 0, ps = 0;
	map<int, int> mp = {{0, 1}};
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		ps += x;
		ans += mp[ps - k];
		mp[ps]++;
	}
	cout << ans;
}