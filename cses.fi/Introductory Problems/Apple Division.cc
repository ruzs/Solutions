#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[20];
	long long sum =0, ans = 1e9;
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i], sum += a[i];
	int all = (1 << n) - 1;
	for(int s = 0; s<=all; ++s) {
		long long cnt =0;
		for(int i =0; i<n; ++i) {
			if (s & (1 << i)) cnt += a[i];
		}
		ans = min(ans, abs(sum - cnt - cnt));
	}
	cout << ans;
}