#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    auto f = [&](auto f, auto& a, int l) {
        if (a.size() == m) {
            for(int i : a) cout << i << ' ';
            cout << '\n';
            return;
        }
        for(int i =l + 1; i<=n; ++i) {
            a.push_back(i);
            f(f, a, i);
            a.pop_back();
        }
    };
    vector<int> a;
    f(f, a, 0);
}