#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, l;
    cin >> n >> l;
    vector<vector<int>> a(n, vector<int>(l));
    vector<int> t(n);
    for(auto & ai : a) for(int & i : ai) cin >> i;
    for(int & i : t) i = mt() % 7676767;
    deque<vector<long long>> s(3*n, vector<long long>(n));
    for(int x =0; x<3*n && x+n<=l; ++x)
        for(int i =0; i<n; ++i)
            for(int j =0; j<n; ++j)
                s[x][i] += 1ll * t[j] * a[i][x + j];
    auto eq = [&](int x) {
        for(int i =0; i<n; ++i) {
            long long L = 0;
            for(int j =0; j<n; ++j) {
                L += a[i][x+j] * s[n][j];
            }
            if (L != s[2*n][i]) return 0;
        }
        return 1;
    };
    vector<int> d(l);
    if (3*n <= l) d[3*n - 1] = eq(0) ? 3*n*n : 0;
    for(int x =3*n; x<l; ++x) {
        s.pop_front();
        s.resize(3*n);
        s.back().resize(n);
        if (x + n <= l) {
            auto & u = s.back();
            for(int k =0; k<20; ++k)
                for(int i =0; i<n; ++i)
                    for(int j =0; j<n; ++j)
                        u[i] += 1ll * t[j] * a[i][x + j];
        }
        d[x] = max(d[x - 1], d[x - 3*n] + (eq(x - 3*n + 1) ? 3*n*n : 0));
    }
    cout << d[l - 1];
}