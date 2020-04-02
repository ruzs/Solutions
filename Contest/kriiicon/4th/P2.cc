#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	const int mod = 1e9+7;
	using pll = pair<long long, long long>;
	auto add = [mod](auto a, auto b) {
		return pll((a.first * b.second + b.first * a.second) % mod, (a.second * b.second) % mod);
	};
	pll sum{0, 1};
	for(int i =0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		sum = add(sum, pll(b, a));
	}
	auto pow = [mod](auto a, auto e) {
		long long x = a % mod, r = 1;
		while (e > 0) {
			if (e & 1) r = r * x % mod;
			x = x * x % mod;
			e >>= 1;
		}
		return r;
	};
	cout << sum.first * pow(sum.second, mod - 2) % mod;
}