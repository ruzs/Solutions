#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(auto & i : a) cin >> i.first >> i.second;
	sort(a.begin(), a.end(), [](auto& a, auto& b) { return a.second < b.second; });
	int ans =0, l =0;
	for(auto & i : a) {
		if (l <= i.first) ans++, l = i.second;
	}
	cout << ans;
}