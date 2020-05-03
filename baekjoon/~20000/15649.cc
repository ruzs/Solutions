#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    auto cb = [&](auto f, vector<int>& a, int v) {
        if (a.size() == m) {
            for(int i : a) cout << i << ' ';
            cout << '\n';
            return;
        }
        for(int i =1; i<=n; ++i) {
            if (v & 1 << i) continue;
            a.push_back(i);
            f(f, a, v | 1 << i);
            a.pop_back();
        }
    };
    vector<int> a;
    cb(cb, a, 0);
}