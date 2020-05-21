#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, Xor = 0;
    long long sum = 0;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x;
        if (x <= 2) cin >> y;
        if (x == 1) {
            sum += y;
            Xor ^= y;
        } else if (x == 2) {
            sum -= y;
            Xor ^= y;
        } else if (x == 3) {
            cout << sum << '\n';
        } else {
            cout << Xor << '\n';
        }
    }
}