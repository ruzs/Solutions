#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll pow(ll a, ll e, ll m) {
	ll r = 1;
	while(e) {
		if (e & 1) r = (a * r) % m;
		a = (a * a) % m;
		e >>= 1;
	}
	return r;
}
int main() {
	ll n, m = 1234567891, hs = 0;
	char s[51];
	cin >> n >> s;
	for(int i =0; i<n; ++i) {
		hs += (pow(31, i, m) * (s[i] - 96)) % m;
		hs %= m;
	}
	cout << hs;
}