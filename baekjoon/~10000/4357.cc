#include <bits/stdc++.h>

using namespace std;

int modpow(int a, int e, int m) {
    long long r = 1, b = a % m;
    while (e) {
        if (e & 1) r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

int Log(int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;
    map<int, int> vals;
    for (int p = n; p >= 1; --p)
        vals[modpow(a, p * n, m)] = p;
    for (int q = 0; q <= n; ++q) {
        int cur = (modpow(a, q, m) * 1ll * b) % m;
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p, b, n;
    while (cin >> p >> b >> n) {
    
        int res = Log(b, n, p);
        if (res == -1) cout << "no solution\n";
        else {
            p--;
            set<int> dv;
            for(int i =1; i*i<=p; ++i) {
                if (p % i == 0) {
                    dv.insert(i);
                    dv.insert(p / i);
                }
            }
            for(int i : dv) {
                if (modpow(b, res % i, p + 1) == n) {
                    cout << res % i << '\n';
                    break;
                }
            }
        }
    }
}