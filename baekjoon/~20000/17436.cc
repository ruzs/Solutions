#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, m;
	cin >> n >> m;
	vector<int> prime(n);
	for(int & i : prime) cin >> i;
	long long ans = 0;
	for(int msk = 1; msk<1<<n; ++msk) {
		int cnt = 0;
		long long mul = 1;
		for(int i =0; i<n; ++i) {
			if (msk & 1 << i) {
				cnt++;
				mul *= prime[i];
			}
		}
		if (cnt & 1) ans += m / mul;
		else ans -= m / mul;
	}
	cout << ans;
}