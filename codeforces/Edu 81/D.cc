#include <bits/stdc++.h>

using namespace std;

auto getFactors(long long x) {
	map<long long, int> r;
	for(long long i =2; i*i<=x; ++i) {
		int c =0;
		while(x % i == 0) c++, x /= i;
		if (c) r[i] = c;
	}
	if (x > 1) r[x] = 1;
	return r;
}
void solve() {
	long long a, m;
	cin >> a >> m;
	auto gcd = __gcd(a, m);
	auto fac = getFactors(m);
	long long ans = m / gcd;
	for(auto i : fac) {
		ans -= (m / gcd) / i.first;
	}
	cout << ans << '\n';
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}