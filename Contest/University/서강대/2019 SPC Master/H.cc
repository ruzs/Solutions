#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	const int mod = 1e9 + 7;
	auto modpow = [](auto a, auto e, int m) {
		long long r = 1, x = a % m;
		for (; e > 0; e >>= 1, x = x * x % m)
			if (e & 1) r = r * x % m;
		return r;
	};
	auto f = [&](int x) {
		return (modpow(2, x, mod) - 1) * 2 % mod;
	};
	cout << (f(n - 1) * 4 + 3) % mod;
}