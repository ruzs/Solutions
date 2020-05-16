#include <bits/stdc++.h>

using namespace std;

typedef complex<double> base;
void fft(vector<base>& a, bool inv) {
	int n = a.size();
	vector<base> r(n / 2);
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
		r[i] = base(cos(ang * i), sin(ang * i));
	}
	/* In NTT, let prr = primitive root. Then,
	int ang = ipow(prr, (mod - 1) / n);
	if(inv) ang = ipow(ang, mod - 2);
	for(int i=0; i<n/2; i++){
	    r[i] = (i ? (1ll * r[i-1] * ang % mod) : 1);
	}
	XOR Convolution : set r[*] = 1.
	OR Convolution : set r[*] = 1, and do following:
	if (!inv) {
	    a[j + k] = u + v;
	    a[j + k + i/2] = u;
	} else {
	    a[j + k] = v;
	    a[j + k + i/2] = u - v;
	}
	*/
	for (int i = 2; i <= n; i <<= 1) {
		for (int j = 0; j < n; j += i) {
			for (int k = 0; k < i / 2; k++) {
				base u = a[j + k], v = a[j + k + i / 2] * r[n / i * k];
				a[j + k] = u + v;
				a[j + k + i / 2] = u - v;
			}
		}
	}
	if (inv) for(auto & x : a) x /= n;
}
template <typename T>
vector<T> multiply(vector<T>& v, vector<T>& w) {
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2;
	while (n < v.size() + w.size()) n <<= 1;
	fv.resize(n);
	fw.resize(n);
	fft(fv, 0);
	fft(fw, 0);
	for (int i = 0; i < n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	vector<T> ret(n);
	for (int i = 0; i < n; i++) ret[i] = (T)round(fv[i].real());
	return ret;
}
vector<long long> multiply(const vector<long long>& v, const vector<long long>& w, long long mod) {
	int n = 2;
	while (n < v.size() + w.size()) n <<= 1;
	vector<base> v1(n), v2(n), r1(n), r2(n);
	for (int i = 0; i < v.size(); i++)
		v1[i] = base(v[i] >> 15, v[i] & 32767);
	for (int i = 0; i < w.size(); i++)
		v2[i] = base(w[i] >> 15, w[i] & 32767);
	fft(v1, 0);
	fft(v2, 0);
	for (int i = 0; i < n; i++) {
		int j = (i ? (n - i) : i);
		base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
		base ans2 = (v1[i] - conj(v1[j])) * base(0, -0.5);
		base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
		base ans4 = (v2[i] - conj(v2[j])) * base(0, -0.5);
		r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
		r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
	}
	fft(r1, 1);
	fft(r2, 1);
	vector<long long> ret(n);
	for (int i = 0; i < n; i++) {
		long long av = (long long)round(r1[i].real());
		long long bv = (long long)round(r1[i].imag()) + (long long)round(r2[i].real());
		long long cv = (long long)round(r2[i].imag());
		av %= mod, bv %= mod, cv %= mod;
		ret[i] = (av << 30) + (bv << 15) + cv;
		ret[i] = (ret[i] % mod + mod) % mod;
	}
	return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    function<vector<long long>(int, int)> dc = [&](int l, int r)->vector<long long> {
        if (l == r) return {a[l], 1};
        int m = l + r >> 1;
        return multiply(dc(l, m), dc(m + 1, r), 100003);
    };
    auto res = dc(0, n - 1);
    int m;
    cin >> m;
    while(m--) {
        int k;
        cin >> k;
        cout << res[n - k] << '\n';
    }
}