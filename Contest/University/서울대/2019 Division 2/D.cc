#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(m);
    string b;
    cin >> b;
    for(auto & i : a) cin >> i;
    vector<int> chk(2 * n + 1, 0);
    vector<vector<int>> ans(2 * n + 1);
    function<void(int, string, vector<int>&)>
    bt = [&](int r, string s, vector<int>& v) {
        int time = 0;
        for(char c : s) time += c == '1' ? 1 : -1;
        if (!chk[time + n]) {
            chk[time + n] = 1;
            ans[time + n] = v;
        }
        if (r >= m) return;

        bt(r + 1, s, v);
        for(int i =0; i<n; ++i) s[i] = (s[i] == a[r][i] ? '0' : '1');
        v.push_back(r + 1);
        bt(r + 1, s, v);
        v.pop_back();
    };
    vector<int> v;
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