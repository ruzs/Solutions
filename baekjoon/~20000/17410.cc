#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(max(320, n + 1));
	vector<vector<int>> bkt(320);
	for(int i =1; i<=n; ++i) {
		cin >> a[i];
		bkt[i / 320].push_back(a[i]);
	}
	for(int i =0; i<320; ++i)
		sort(bkt[i].begin(), bkt[i].end());
	int m;
	cin >> m;
	while(m--) {
		int cmd, i, j, k;
		cin >> cmd;
		if (cmd == 1) {
			cin >> i >> j;
			auto & b = bkt[i / 320];
			auto x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			b[x] = a[i] = j;
			while(x > 0 && b[x] < b[x - 1]) swap(b[x], b[x - 1]), x--;
			while(x + 1 < b.size() && b[x] > b[x + 1]) swap(b[x], b[x + 1]), x++;
		} else {
			cin >> i >> j >> k;
			int ans = 0;
			for(int x = i; x <= j && x / 320 < i / 320 + 1; ++x)
				ans += a[x] > k;
			for(int x = i / 320 + 1; x < j / 320; ++x) {
				auto & b = bkt[x];
				ans += b.end() - upper_bound(b.begin(), b.end(), k);
			}
			if (i / 320 != j / 320)
				for(int x = j / 320 * 320; x <= j; ++x)
					ans += a[x] > k;
			cout << ans << '\n';
		}
	}
}