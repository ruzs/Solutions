#include <bits/stdc++.h>

using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0, k; i < n; i++) {
        for (k = n >> 1; (j ^= k) < k; k >>= 1);
        if (i < j) swap(a[i], a[j]);
    }
    double ang = 2 * PI / n * (inv ? -1 : 1);
    vector<cd> w(n / 2);
    for (int i = 0; i < w.size(); ++i)
        w[i] = cd(cos(ang * i), sin(ang * i));
    for (int k = 2; k <= n; k <<= 1) {
        int s = n / k;
        for (int i = 0; i < n; i += k)
            for (int j = 0; j < k / 2; j++) {
                cd v = a[i + j + k / 2] * w[s * j];
                a[i + j + k / 2] = a[i + j] - v;
                a[i + j] += v;
            }
    }
    if (inv) for (cd& x : a) x /= n;
}
template <typename T>
vector<T> multiply(vector<T>& a, vector<T>& b, T mod = 0) {
    int n = 2;
    while (n <= a.size() + b.size()) n <<= 1;
    vector<cd> A(n), B(n), C(n), D(n);

    for (int i = 0; i < a.size(); i++)
        A[i] = {a[i] >> 15, a[i] & 32767};
    for (int i = 0; i < b.size(); i++)
        B[i] = {b[i] >> 15, b[i] & 32767};
    fft(A, 0);
    fft(B, 0);
    for (int i = 0; i < n; i++) {
        int j = i ? n - i : i;
        cd f1 = (A[i] + conj(A[j])) * cd(0.5, 0),
           f2 = (A[i] - conj(A[j])) * cd(0, -0.5),
           f3 = (B[i] + conj(B[j])) * cd(0.5, 0),
           f4 = (B[i] - conj(B[j])) * cd(0, -0.5);
        C[i] = f1 * (f3 + f4 * cd(0, 1));
        D[i] = f2 * (f3 + f4 * cd(0, 1));
    }
    fft(C, 1);
    fft(D, 1);
    vector<T> ans(a.size() + b.size() + 1);
    for (int i = 0; i < ans.size(); i++) {
        T a = (T)round(C[i].real()),
          b = (T)round(C[i].imag()) + (T)round(D[i].real()),
          c = (T)round(D[i].imag());
        if (mod) a %= mod, b %= mod, c %= mod;
        ans[i] = (a << 30) + (b << 15) + c;
        if (mod) ans[i] = (ans[i] % mod + mod) % mod;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1), b(m + 1);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    long long res = 0;
    for (auto i : multiply(a, b)) res ^= i;
    cout << res;
}