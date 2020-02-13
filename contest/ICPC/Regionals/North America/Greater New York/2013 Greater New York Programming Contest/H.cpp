#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

ull mypow(ull a, ull e) {
	ull r = 1;
	while(e) {
		if (e & 1) r *= a;
		a *= a;
		e /= 2;
	}
	return r;
}
ull comb(ull n, ull r) {
	ull ans = 1;
	map<ull, int> fac;
	for(ull i =2; i<=r; ++i) {
		ull t =i;
		for(ull j =2; j*j<=t; ++j){
			while(t % j == 0) fac[j]++, t /= j;
		}
		if (t > 1) fac[t]++;
	}
	for(ull i =n - r + 1; i<=n; ++i) {
		ull t =i;
		for(auto &j : fac) {
			while(j.second && t % j.first == 0) t /= j.first, j.second--;
		}
		ans *= t;
	}
	return ans;
}
ull t, n, k, r, c;
int main() {
	cin >> t;
	while(t--) {
		cin >> n >> k >> r >> c;
		cout << n << ' ';
		if (!r) cout << "1\n";
		else if (!c) cout << mypow(k, r) << '\n';
		else cout << comb(r, min(c, r - c)) * mypow(k, min(c, r - c)) << '\n';
	}
}
