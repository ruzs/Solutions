#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	sort(a.begin(), a.end());
	long long ans = 0, cnt = 0, div = -1;
	for(int i =0, j =0; j<n; ++j) {
		if (a[j] / d != div) {
			ans += cnt * (cnt - 1) / 2;
			div = a[j] / d;
			cnt = 1;
		} else {
			cnt++;
		}
	}
	ans += cnt * (cnt - 1) / 2;
	cout << ans;
}