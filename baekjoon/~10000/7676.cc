#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, n;
	while (cin >> r >> n) {
		if (r < 0 && n < 0) break;
		vector<int> a(n);
		for(int & i : a) cin >> i;
		sort(a.begin(), a.end());
		int ans = 0;
		for(int i =0, j; i<n;) {
			j = 0;
			while (i + j + 1 < n && a[i] + r >= a[i + j + 1]) j++;
			i += j;
			j = 0;
			while (i + j < n && a[i] + r >= a[i + j]) j++;
			i += j;
			ans++;
		}
		cout << ans << '\n';
	}
}