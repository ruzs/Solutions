#include <bits/stdc++.h>

using namespace std;

long long modpow(long long a, long long e, long long m) {
    __int128_t r = 1, b = a % m;
    while (e) {
        if (e & 1) r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

bool check_composite(long long n, long long a, long long d, int s) {
    auto x = modpow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (__int128_t)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(long long n) {
    if (n < 2)
        return false;

    int r = 0;
    long long d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
long long f(long long x, long long c, long long mod) {
    return ((__int128_t)x * x % mod + c) % mod;
}
long long rho(long long n, long long x0 = 2, long long c = 1) {
    long long x = x0;
    long long y = x0;
    long long g = 1;
	int cnt = 0;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = __gcd(abs(x - y), n);
		if (++cnt > 50000) return -1;
    }
    return g;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;
	multiset<long long> ans;
	function<void(long long)> go = [&](long long x) {
		if (x == 1) return;
		if (MillerRabin(x)) {
			ans.insert(x);
			return;
		}
		if (x < 1e6) {
			for(int i =2; i*i<=x; ++i) {
				while (x % i == 0) {
					ans.insert(i);
					x /= i;
				}
			}
			if (x > 1) ans.insert(x);
			return;
		}
		long long g;
		for(int i =1; i<=5; ++i) {
			for(int j =-3; j<=3; ++j) {
				if (!j) continue;
				g = rho(x, i, j);
				if (g > 0) break;
			}
		}
		go(g);
		go(x / g);
	};
	go(n);
	for(auto i : ans) cout << i << '\n';
}