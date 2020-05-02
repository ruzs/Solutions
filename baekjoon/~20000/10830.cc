#include <bits/stdc++.h>

using namespace std;
using matrix = vector<vector<int>>;

matrix mul(matrix a, matrix b) {
    int n = a.size();
    matrix r(n, vector<int>(n));
    for(int i =0; i<n; ++i)
        for(int j =0; j<n; ++j)
            for(int k =0; k<n; ++k) {
                r[i][k] += a[i][j] * b[j][k];
                r[i][k] %= 1000;
            }
    return r;
}
matrix pow(matrix a, long long e) {
    int n = a.size();
    matrix r(n, vector<int>(n));
    for(int i =0; i<n; ++i) r[i][i] = 1;
    for(; e > 0; e >>= 1, a = mul(a, a))
        if (e & 1) r = mul(r, a);
    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long k;
    cin >> n >> k;
    matrix a(n, vector<int>(n));
    for(auto & i : a) for(int & j : i) cin >> j;
    auto r = pow(a, k);
    for(auto & i : r) {
        for(int j : i) cout << j << ' ';
        cout << '\n';
    }
}