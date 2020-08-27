#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	int sum = 0, ans = -1e9;
	for(int i =0, j =0; j<n; ++j) {
		sum += a[j];
		if (j - i + 1 == k) {
			ans = max(ans, sum);
			sum -= a[i++];
		}
	}
	cout << ans;
}