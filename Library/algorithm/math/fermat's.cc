#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int modpow(long long a, int e, int m) {
	int r = 1;
	while(e) {
		if (e & 1) r = (a * r) % m;
		a = (a * a) % m;
		e >>= 1;
	}
	return r;
}

// 1/x (m) = pow(x, m - 2, m)