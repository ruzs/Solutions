#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a[5];
	for(int i =1; i<=4; ++i) cin >> a[i];
	auto shift = [](string & s, int d) {
		if (d > 0) s = s.back() + s, s.pop_back();
		else s = s.substr(1) + s.front();
	};
	int n;
	cin >> n;
	while(n--) {
		int x, d;
		cin >> x >> d;
		int l = x, r = x;
		while (r < 4 && a[r][2] != a[r + 1][6]) r++;
		while (l > 1 && a[l][6] != a[l - 1][2]) l--;
		for(int i =l; i<=r; ++i) shift(a[i], i % 2 == x % 2 ? d : d > 0 ? -1 : 1);
	}
	int ans = 0;
	for(int i =1; i<=4; ++i) ans += a[i][0] & 1 ? 1 << i - 1 : 0;
	cout << ans;
}