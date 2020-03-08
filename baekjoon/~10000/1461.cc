#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a, b;
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		if (x < 0) a.push_back(-x);
		else b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0;
	if (a.empty() && b.empty()) {
		cout << 0;
	} else if (a.empty() || b.empty()) {
		if (a.empty()) swap(b, a);
		ans += a.back();
		for(int i =a.size() - m - 1; i>=0; i -= m) {
			ans += a[i] * 2;
		}
		cout << ans;
	} else {
		if (a.back() > b.back()) swap(a, b);
		for(int i =a.size() - 1; i>=0; i -= m) {
			ans += a[i] * 2;
		}
		ans += b.back();
		for(int i =b.size() - m - 1; i>=0; i -= m) {
			ans += b[i] * 2;
		}
		cout << ans;
	}
}