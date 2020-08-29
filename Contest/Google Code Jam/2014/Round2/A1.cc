#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt; cin >> tt;
	for(int t = 1; t <= tt; ++t) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for(int & i : a) cin >> i;
		sort(a.begin(), a.end());
		int i =0, j =n-1;
		int ans = 0;
		while (i < j) {
			if (a[i] + a[j] <= x) {
				ans++;
				i++;
				j--;
			} else {
				ans++;
				j--;
			}
		}
		if (i == j) ans++;
		cout << "Case #" << t << ": " << ans << '\n';
	}
}