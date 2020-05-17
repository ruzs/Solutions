#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r, m;
    cin >> n >> r >> m;
    vector<int> a(n);
    for(int i =0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i =0; i<n; ++i) a.push_back(a[i] + m);
    int sum = 0, mx = 0;
    for(int i =1; i<a.size(); ++i) {
        int d = a[i] - a[i - 1] - 2 * r;
        sum += d;
        mx = max(mx, sum);
        if (sum < 0) sum = 0;
    }
    cout << (mx + 1) / 2;
}