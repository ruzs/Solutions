#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	int sum = 0, ans = 0;
	for(int i =0, j =0; j<n; ++j) {
		sum += a[j];
		while (sum > m) sum -= a[i++];
		if (sum == m) ans++;
	}
	cout << ans;
}