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
    for (int k = 2; k <= n; k <<= 1) {
        double ang = 2 * PI / k * (inv ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += k) {
            cd w(1);
            for (int j = 0; j < k / 2; j++) {
                cd v = a[i + j + k / 2] * w;
                a[i + j + k / 2] = a[i + j] - v;
                a[i + j] += v;
                w *= wlen;
            }
        }
    }
    if (inv) for (cd& x : a) x /= n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<cd> a(1 << 21);
    vector<int> p = {2};
    bitset<1<<20> np;
    for(long long i =3, j; i<1e6; i+=2) {
        if(np[i]) continue;
        a[i] = 1;
        p.push_back(i);
        for(j =i*i; j<1e6; j+=i) np[j] = 1;
    }
    for(int i : p) if (i < 5e5) a[i * 2] = 1; else break;
    fft(a, 0);
    for(int i =0; i<1<<21; ++i) a[i] *= a[i];
    fft(a, 1);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int q = n >> 1;
        cout << (long long)round(a[n].real()) / 2 << '\n';
    }
}