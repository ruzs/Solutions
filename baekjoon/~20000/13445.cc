#include <bits/stdc++.h>

using namespace std;

using cd = complex<double>;

void fft(vector<cd>& a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0, k; i < n; i++) {
        for (k = n >> 1; (j ^= k) < k; k >>= 1);
        if (i < j) swap(a[i], a[j]);
    }
    for (int k = 2; k <= n; k <<= 1) {
        int s = n / k;
        for (int i = 0; i < n; i += k)
            for (int j = 0; j < k / 2; j++) {
                cd v = a[i + j + k / 2];
                a[i + j + k / 2] = a[i + j] - v;
                a[i + j] += v;
            }
    }
    if (inv) for (cd& x : a) x /= n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<cd> a(1 << 17);
    int ax = 0;
    a[0] = 1;
    for(int i =0; i<n; ++i) {
        int x; cin >> x;
        a[ax ^= x] += 1;
    }
    fft(a, 0);
    for(int i =0; i<1<<17; ++i) a[i] *= a[i];
    fft(a, 1);
    long long ans = (long long)round(a[0].real()) - n - 1 >> 1;
    m = min(m, 1 << 17);
    for(int i =1; i<m; ++i) {
        ans += (long long)round(a[i].real()) >> 1;
    }
    cout << ans;
}