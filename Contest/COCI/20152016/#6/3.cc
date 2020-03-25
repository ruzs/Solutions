#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), k(n);
	for(int i =0; i<n; ++i) cin >> a[i];
	for(int i =1; i<n; ++i) {
		k[i] = k[i - 1] + (a[i] ^ a[i - 1] ? a[i] < a[i - 1] ? -1 : 1 : 0);
	}
	unordered_map<int, int> mp;
	int zero = 0;
	for(int i =0; i<n; ++i) {
		if (k[i] == 0) {
			if (a[i] == a[0]) zero++;
		} else if ((a[i] - a[0]) % k[i] == 0) {
			mp[(a[i] - a[0]) / k[i]]++;
		}
	}
	pair<int, int> ans = {0, 0};
	for(auto & i : mp) {
		if (i.first < 0) continue;
		if (ans.second < i.second) ans = i;
	}
	cout << ans.second + zero << '\n' << ans.first;
}