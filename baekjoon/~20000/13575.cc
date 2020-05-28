#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cd;
void fft(vector<cd>& a, bool inv) {
	int n = a.size();
	vector<cd> r(n / 2);
	for (int i = 1, j = 0; i < n; i++) {
		int bit = (n >> 1);
		while (j >= bit) {
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for (int i = 0; i < n / 2; i++) {
		r[i] = cd(cos(ang * i), sin(ang * i));
	}
	for (int i = 2; i <= n; i <<= 1) {
		for (int j = 0; j < n; j += i) {
			for (int k = 0; k < i / 2; k++) {
				cd u = a[j + k], v = a[j + k + i / 2] * r[n / i * k];
				a[j + k] = u + v;
				a[j + k + i / 2] = u - v;
			}
		}
	}
	if (inv) for(auto & x : a) x /= n;
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
        if (ans[i]) ans[i] = 1;
        if (mod) ans[i] = (ans[i] % mod + mod) % mod;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<long long> a;
    for(int i =0; i<n; ++i) {
        int x; cin >> x;
        if (a.size() < x + 1) a.resize(x + 1);
        a[x]++;
    }
    auto modpow = [](auto a, auto e) {
        vector<long long> r(1, 1);
        for (; e > 0; e >>= 1, a = multiply(a, a))
            if (e & 1) r = multiply(r, a);
        return r;
    };
    auto r = modpow(a, k);
    for(int i =0; i<r.size(); ++i) if (r[i]) cout << i << ' ';
}