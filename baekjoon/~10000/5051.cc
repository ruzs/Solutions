#include <bits/stdc++.h>

using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0, bit; i < n; i++) {
        for (bit = n >> 1; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (inv ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv) for (cd & x : a) x /= n;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
    vector<int> a(1 << 19);
	for(long long i =1; i<n; ++i) {
        a[i * i % n]++;
    }
	vector<cd> fa(a.begin(), a.end());
    fa.resize(1 << 20);
	fft(fa, 0);
	for(int i =0; i<fa.size(); ++i) fa[i] = fa[i] * fa[i];
	fft(fa, 1);
	long long ans = 0;
    for(int i =0; i<fa.size(); ++i) ans += a[i % n] * round(fa[i].real());
    long long t = 0;
    for(long long i =1; i<n; ++i) t += a[2 * i * i % n];
    ans -= t;
    ans /= 2;
    ans += t;
	cout << ans;
}