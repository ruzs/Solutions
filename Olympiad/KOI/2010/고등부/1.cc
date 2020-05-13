#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i =0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    long long mn = 3e9, x, y, z;
    for(int i =0; i<n; ++i) {
        int l = 0, r = n - 1;
        while (l != i && r != i) {
            if (mn > abs(a[l] + a[i] + a[r])) {
                mn = abs(a[l] + a[i] + a[r]);
                x = a[l];
                y = a[i];
                z = a[r];
            }
            if (abs(a[l + 1] + a[i] + a[r]) < abs(a[l] + a[i] + a[r - 1]))
                l++;
            else r--;
        }
    }
    cout << x << ' ' << y << ' ' << z;
}