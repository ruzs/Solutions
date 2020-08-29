#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, b;
	cin >> n >> k >> b;
	vector<int> a(n + 1, 1);
	while (b--) {
		int x;
		cin >> x;
		a[x] = 0;
	}
	for(int i =1; i<=n; ++i)
		a[i] += a[i - 1];
	int ans = 1e9;
	for(int i =k; i<=n; ++i)
		ans = min(ans, k - (a[i] - a[i - k]));
	cout << ans;
}