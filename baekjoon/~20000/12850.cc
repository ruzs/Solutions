#include <bits/stdc++.h>

using namespace std;

using matrix = vector<vector<long long>>;
const int mod = 1e9 + 7;

matrix operator * (matrix const& a, matrix const& b) {
    matrix r(a.size(), vector<long long>(b[0].size()));
    for(int i =0; i<a.size(); ++i)
    for(int j =0; j<b.size(); ++j)
    for(int k =0; k<b[0].size(); ++k) {
        r[i][k] += (a[i][j] * b[j][k]) % mod;
        r[i][k] %= mod;
    }
    return r;
}
auto modpow = [](matrix a, auto e) {
    matrix r(a.size(), vector<long long>(a.size()));
    for(int i =0; i<a.size(); ++i) r[i][i] = 1;
    for (; e > 0; e >>= 1, a = a * a)
        if (e & 1) r = r * a;
    return r;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    matrix a = {
        {0, 1, 0, 0, 1, 0 ,0, 0},
        {1, 0, 1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 1, 1, 0},
        {1, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
    };
    auto r = modpow(a, n);
    cout << r[0][0];
}