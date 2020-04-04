#include <bits/stdc++.h>

using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;

	auto s = to_string(n);
	reverse(s.begin(), s.end());
	for(char & c : s) {
		if (c == '6') c = '9';
		else if (c == '9') c = '6';
		else if (c == '3' || c == '4' || c == '7') {
			cout << "no";
			return 0;
		}
	}
	auto rn = stoll(s);

	if (MillerRabin(n) && MillerRabin(rn)) cout << "yes";
	else cout << "no";
}