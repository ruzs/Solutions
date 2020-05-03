#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b;
    for(int & i : a) cin >> i;
    sort(a.begin(), a.end());
    auto f = [&](auto f) {
        if (b.size() == m) {
            for(int i : b) cout << i << ' ';
            cout << '\n';
            return;
        }
        for(int i =0; i<n; ++i) {
            b.push_back(a[i]);
            f(f);
            b.pop_back();
        }
    };
    f(f);
}