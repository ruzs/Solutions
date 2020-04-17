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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    while(n--) {
        long long x;
        cin >> x;
        if (MillerRabin(x * 2 + 1)) cnt++;
    }
    cout << cnt;
}