#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	int cnt = 0, ans = 1e9;
	for(int i =0, j =0; j<n; ++j) {
		if (a[j] == 1) cnt++;
		if (cnt > k) cnt--, i++;
		while (i < j && a[i] != 1) i++;
		if (cnt == k) ans = min(ans, j - i + 1);
	}
	if (ans < 1e9) cout << ans;
	else cout << -1;
}