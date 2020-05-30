#include <bits/stdc++.h>

using namespace std;

const int mod = 1e6 + 3;
using matrix = vector<vector<long long>>;
matrix operator * (matrix const& a, matrix const& b) {
    matrix r(a.size(), vector<long long>(b[0].size()));
    for(int i =0; i<a.size(); ++i)
        for(int j =0; j<b.size(); ++j)
            for(int k =0; k<b[0].size(); ++k)
                r[i][k] = (r[i][k] + a[i][j] * b[j][k]) % mod;
    return r;
}
auto modpow = [](auto a, auto e) {
    matrix r(a.size(), vector<long long>(a.size()));
    for(int i =0; i<a.size(); ++i) r[i][i] = 1;
    for (; e > 0; e >>= 1, a = a * a)
        if (e & 1) r = r * a;
    return r;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s, e, t;
    cin >> n >> s >> e >> t;
    matrix a(5 * n, vector<long long>(5 * n));

    for(int i =0; i<n; ++i) {
        string s;
        cin >> s;
        for(int j =0; j<n; ++j) {
            int k = i * 4 + n;
            if (s[j] == '1') {
                a[i][j] = 1;
            } else if (s[j] == '2') {
                a[i][k] = 1;
                a[k][j] = 1;
            } else if (s[j] == '3') {
                a[i][k] = 1;
                a[k][k + 1] = 1;
                a[k + 1][j] = 1;
            } else if (s[j] == '4') {
                a[i][k] = 1;
                a[k][k + 1] = 1;
                a[k + 1][k + 2] = 1;
                a[k + 2][j] = 1;
            } else if (s[j] == '5') {
                a[i][k] = 1;
                a[k][k + 1] = 1;
                a[k + 1][k + 2] = 1;
                a[k + 2][k + 3] = 1;
                a[k + 3][j] = 1;
            }
        }
    }
    auto r = modpow(a, t);
    cout << r[s - 1][e - 1];
}