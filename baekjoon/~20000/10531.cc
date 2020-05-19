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

	int n, m;
	cin >> n;
	vector<cd> a(1 << 19);
	for(int i =0; i<n; ++i) {
		int x; cin >> x;
		a[x] += 1;
	}
	fft(a, 0);
	for(int i =0; i<a.size(); ++i) a[i] = a[i] * a[i] + a[i];
	fft(a, 1);
	cin >> n;
	int ans = 0;
	while(n--) {
		int x; cin >> x;
		if (round(a[x].real()) > 0) ans++;
	}
	cout << ans;
}