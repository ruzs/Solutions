#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(x), b(y);
	for(int i =0; i<x; ++i) cin >> a[i];
	for(int i =0; i<y; ++i) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0;
	if (n & 1) n--, ans += a.back(), a.pop_back();
	while(n) {
		if (a.size() < 2 || b.back() > a[a.size() - 1] + a[a.size() - 2])
			n -= 2, ans += b.back(), b.pop_back();
		else n -= 2, ans += a[a.size() - 1] + a[a.size() - 2], a.pop_back(), a.pop_back();
	}
	cout << ans;
}