#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int d[1001][1001];
    memset(d, -1, sizeof d);
    function<int(int, int)> dp = [&](int l, int r) {
        int & ref = d[l][r];
        if (~ref) return ref;
        if (l > r) return ref = 0;
        if (l == r) return ref = 1;
        ref = dp(l + 1, r) + dp(l, r - 1) - dp(l + 1, r - 1);
        if (s[l] == s[r]) ref += dp(l + 1, r - 1) + 1;
        return ref = (ref % 10007 + 10007) % 10007;
    };
    cout << dp(0, n - 1);
}