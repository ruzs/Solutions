#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<tuple<int, int, int>> a;
    for(int i =1; i<=n; ++i) {
        int s, e;
        cin >> s >> e;
        a.emplace_back(s, 0, i);
        a.emplace_back(e, 1, i);
    }
    sort(a.begin(), a.end());
    int cnt = 0, mx = 0;
    for(auto & [x, y, z] : a) {
        if (y) cnt--;
        else cnt++;
        mx = max(mx, cnt);
    }
    set<int> ans;
    for(auto & [x, y, z] : a) {
        if (y) ans.erase(z);
        else ans.insert(z);
        if (ans.size() == mx) {
            cout << ans.size() << '\n';
            for(int i : ans) cout << i << ' ';
            return 0;
        }
    }
}