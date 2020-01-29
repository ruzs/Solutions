#include <bits/stdc++.h>
 
using namespace std;
 
auto getFactors(int x) {
	map<int, int> factors;
	for(int i =2; i*i<=x; ++i) {
		int c =0;
		while(x % i == 0) c++, x /= i;
		if (c) factors[i] = c;
	}
	if (x > 1) factors[x] = 1;
	return factors;
}
 
void solve() {
	int n;
	cin >> n;
	auto fac = getFactors(n);
	if (fac.size() == 1) {
		auto x = fac.begin();
		if (x->second < 6) cout << "NO\n";
		else cout << "YES\n"
			<< x->first << ' '
			<< pow(x->first, 2) << ' '
			<< pow(x->first, x->second - 3) << '\n';
	}
	else if (fac.size() == 2) {
		auto x = fac.begin(), y = x; y++;
		if (x->second + y->second < 4) cout << "NO\n";
		else cout << "YES\n"
			<< x->first << ' '
			<< y->first << ' '
			<< n / x->first / y->first << '\n';
	}
	else {
		auto x = fac.begin(), y = x; y++;
		cout << "YES\n"
			<< x->first << ' ' << y->first << ' ' << n / x->first / y->first << '\n';
	}
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}