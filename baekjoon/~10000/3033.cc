#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	auto pos = [&](int x) {
		if (x > n) return 0;
		const int m = 1e6+7;
		long long p = 1, h = 0;
		for(int i =0; i<x; ++i) {
			h = (h * 31 + (s[i] - 'a' + 1)) % m;
			if (i) p = p * 31 % m;
		}
		vector<int> v(m, -1);
		v[h] = 0;
		for(int i =x; i<n; ++i) {
			h = (h - (s[i - x] - 'a' + 1) * p % m + m) % m;
			h = (h * 31 + (s[i] - 'a' + 1)) % m;
			if (~v[h]) {
				if (equal(s.begin() + v[h], s.begin() + v[h] + x, s.begin() + i - x + 1))
					return 1;
			}
			v[h] = i - x + 1;
		}
		return 0;
	};
	int ans = 0, j = n;
	while(j /= 2) {
		while(pos(ans + j)) ans += j;
	}
	cout << ans;
}