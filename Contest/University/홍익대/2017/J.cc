#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n)), t;
    for(int i =0; i<n; ++i) for(int j =0; j<n; ++j)
        cin >> s[i][j];
    auto press = [&](int y, int x) {
        t[y][x] ^= 1;
        if (y > 0) t[y - 1][x] ^= 1;
        if (x > 0) t[y][x - 1] ^= 1;
        if (y < n - 1) t[y + 1][x] ^= 1;
        if (x < n - 1) t[y][x + 1] ^= 1;
    };
    int ans = 1e9;
    for(int msk = 0; msk < 1 << n; ++msk) {
        t = s;
        int cnt = 0;
        for(int j =0; j<n; ++j)
            if (msk & 1 << j) {
                cnt++;
                press(0, j);
            }
        for(int i =1; i<n; ++i)
            for(int j =0; j<n; ++j)
                if (t[i - 1][j]) {
                    cnt++;
                    press(i, j);
                }
        for(int j =0; j<n; ++j)
            if (t[n - 1][j]) {
                cnt = 1e9;
                break;
            }
        ans = min(ans, cnt);
    }
    cout << (ans < 1e9 ? ans : -1);
}