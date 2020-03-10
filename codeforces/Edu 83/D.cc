#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const long long mod = 998244353;
	int n, m;
	cin >> n >> m;
	vector<long long> factorial = {1};
	for(int i =1; i<=m; ++i) {
		factorial.push_back((factorial.back() * i) % mod);
	}
	auto modpow = [mod](long long a, int e) {
		long long ans = 1;
		if (e < 0) return ans;
		while(e) {
			if (e & 1) ans = (ans * a) % mod;
			a = (a * a) % mod;
			e >>= 1;
		}
		return ans;
	};
	auto combination = [&, mod](int n, int r) {
		if (n < r || n < 0 || r < 0) return 0ll;
		return (factorial[n] * modpow((factorial[r] * factorial[n - r]) % mod, mod - 2)) % mod;
	};
	int ans = 0;
	for(int i =1; i<=m; ++i) {
		ans += ((1ll * (i - 1) * combination(i - 2, n - 3)) % mod * modpow(2, n - 3)) % mod;
		ans %= mod;
	}
	cout << ans;
}