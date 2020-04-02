#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int mod = 1e9+7;
	int a, b;
	cin >> a >> b;
	auto fact = [mod](int a) {
		long long r = 1;
		for(int i =1; i<=a; ++i) r = r * i % mod;
		return r;
	};
	auto pow = [mod](auto a, auto e) {
		long long x = a % mod, r = 1;
		while (e > 0) {
			if (e & 1) r = r * x % mod;
			x = x * x % mod;
			e >>= 1;
		}
		return r;
	};
	cout << fact(a) * pow(fact(b) * fact(a - b) % mod, mod - 2) % mod;
}