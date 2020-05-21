#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int d[10001][101];
    function<int(int, int)> dp = [&](int x, int y) {
        if (x < y) swap(x, y);
        int & ref = d[x][y];
        if (~ref) return ref;
        if (x % y == 0) return ref = x / y;
        if (x >= 3 * y) return ref = dp(x - y, y) + 1;
        ref = 1e9;
        for(int i =1; i+i<=x; ++i)
            ref = min(ref, dp(i, y) + dp(x - i, y));
        for(int i =1; i+i<=y; ++i)
            ref = min(ref, dp(x, i) + dp(x, y - i));
        return ref;
    };
    memset(d, -1, sizeof d);
    cout << dp(n, m);
}