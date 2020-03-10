#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, k, mod;
	cin >> n >> k >> mod;
	vector<int> F = {1}, G = {1};
	auto pow = [mod](auto a, auto e) {
		long long x = a % mod, r = 1;
		while (e > 0) {
			if (e & 1) r = r * x % mod;
			x = x * x % mod;
			e >>= 1;
		}
		return r;
	};
	for(int i =1; i<mod; ++i) {
		F.push_back((F.back() * i) % mod);
		G.push_back(pow(F.back(), mod - 2));
	}
	long double q = 1;
	while(q * mod <= n) q *= mod;
	long long ans = 1, p = q;
	while(n || k) {
		if (k / p > n / p) {
			cout << 0;
			return 0;
		}
		ans *= F[n / p] * G[k / p] % mod * G[n / p - k / p] % mod;
		ans %= mod;
		n %= p;
		k %= p;
		p /= mod;
	}
	cout << ans;
}