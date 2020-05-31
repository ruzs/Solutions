#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    double ps = 1, mx = 0;
    for(int i =0; i<n; ++i) {
        double a;
        cin >> a;
        ps *= a;
        mx = max(mx, ps);
        if (ps < 1) ps = 1;
    }
    cout.precision(3);
    cout << fixed << mx;
}