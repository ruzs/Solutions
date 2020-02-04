#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x = 0;
	cin >> n;
	vector<pair<int, int>> a(n << 1);
	for(auto& i : a) cin >> i.first, i.second = x ^= 1;
	sort(a.begin(), a.end());
	int cnt = 0, ans = 0;
	for(auto& i : a) {
		if (i.second) cnt++;
		else cnt--;
		ans = max(ans, cnt);
	}
	cout << ans;
}