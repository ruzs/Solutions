#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, mod;
	cin >> n >> k >> mod;
	vector<int> p(4000005, 0);
	bitset<4000005> np;
	long long i, j;
	for (i = 2; i <= n; ++i) {
		if (np[i]) continue;
		for(j = i; j <= n; j += i) np[j] = 1;
		for(j = i; j <= n; j *= i) {
			p[i] += n / j - k / j - (n - k) / j;
		}
	}
	long long ans = 1;
	auto pow = [mod](auto a, auto e) {
		long long x = a % mod, r = 1;
		while (e > 0) {
			if (e & 1) r = r * x % mod;
			x = x * x % mod;
			e >>= 1;
		}
		return r;
	};
	for(int i =1; i<=n; ++i) {
		ans *= pow(i, p[i]);
		ans %= mod;
	}
	cout << ans;
}