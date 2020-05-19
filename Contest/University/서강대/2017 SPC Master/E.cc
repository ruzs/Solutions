#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> s(10), t;
    for(int i =0; i<10; ++i)
        cin >> s[i];
    auto turn = [&](int y, int x) {
        t[y][x] = t[y][x] == 'O' ? '#' : 'O'; 
    };
    auto press = [&](int y, int x) {
        turn(y, x);
        if (y > 0) turn(y - 1, x);
        if (y < 9) turn(y + 1, x);
        if (x > 0) turn(y, x - 1);
        if (x < 9) turn(y, x + 1);
    };
    int ans = 1e9;
    for(int msk = 0; msk < 1 << 10; ++msk) {
        t = s;
        int cnt = 0;
        for(int j =0; j<10; ++j)
            if (msk & 1 << j) {
                cnt++;
                press(0, j);
            }
        for(int i =1; i<10; ++i)
            for(int j =0; j<10; ++j)
                if (t[i - 1][j] == 'O') {
                    cnt++;
                    press(i, j);
                }
        for(int j =0; j<10; ++j)
            if (t[9][j] == 'O') {
                cnt = 1e9;
                break;
            }
        ans = min(ans, cnt);
    }
    if (ans < 1e9) cout << ans;
    else cout << -1;
}