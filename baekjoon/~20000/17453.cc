#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<bitset<100>> a(m);
    bitset<100> b;
    cin >> b;
    for(auto & i : a) cin >> i;
    vector<int> chk(2 * n + 1, 0), v;
    vector<vector<int>> ans(2 * n + 1);
    function<void(int, bitset<100>&, vector<int>&)>
    bt = [&](int r, bitset<100>& s, vector<int>& v) {
        if (r == m) {
            int time = 0;
            for(int i =0; i<n; ++i) time += s[i] ? 1 : -1;
            if (!chk[time + n]) {
                chk[time + n] = 1;
                ans[time + n] = v;
            }
            return;
        }

        bt(r + 1, s, v);
        s ^= a[r];
        v.push_back(r + 1);
        bt(r + 1, s, v);
        s ^= a[r];
        v.pop_back();
    };
    bt(0, b, v);
    for(int i =0; i<2*n+1; ++i) {
        if (ans[i].empty()) cout << (chk[i] ? "0\n" : "-1\n");
        else {
            cout << ans[i].size() << ' ';
            for(int j : ans[i]) cout << j << ' ';
            cout << '\n';
        }
    }
}