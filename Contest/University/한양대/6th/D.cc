#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    t %= (2 * n - 1) * 2;
    if (t == 0) t = (2 * n - 1) * 2;
    if (t > 2 * n) cout << 2 * n - (t - 2 * n);
    else cout << t;
}