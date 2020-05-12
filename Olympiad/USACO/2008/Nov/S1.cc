#include <bits/stdc++.h>

using namespace std;

int n, h, d[55001];
int p[100], c[100];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(d, 64, sizeof d);
    d[0] = 0;
    cin >> n >> h;
    for(int i =0; i<n; ++i)
        cin >> p[i] >> c[i];
    for(int i =0; i<n; ++i) {
        for(int j =0; j<=h; ++j)
            if (d[j + p[i]] > d[j] + c[i])
                d[j + p[i]] = d[j] + c[i];
    }
    int ans = 1e9;
    for(int i =h; i<=h + 5000; ++i) {
        if (ans > d[i])
            ans = d[i];
    }
    cout << ans;
}