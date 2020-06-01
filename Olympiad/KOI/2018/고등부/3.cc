#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(3));
    for(int i =0; i<n; ++i)
        for(int j =0; j<m; ++j)
            cin >> a[j][i];
    sort(a.begin(), a.end());
    if (n == 2) for(int j =0; j<m; ++j) a[j][2] = j;
    vector<set<pair<int, int>>> d(m + 1);
    int ans = 0;
    for(auto & i : a) {
        auto pos = [&](int x) {
            if (x > m || d[x].empty() || d[x].begin()->first > i[1]) return 0;
            if (prev(d[x].upper_bound({i[1], i[2]}))->second < i[2]) return 1;
            return 0;
        };
        int x = 0, j = m;
        while(j /= 2) {
            while(pos(x + j)) x += j;
        }
        auto it = d[x + 1].insert({i[1], i[2]}).first;
        while(next(it) != d[x + 1].end() && it->second < next(it)->second)
            d[x + 1].erase(next(it));
        ans = max(ans, x + 1);
    }
    cout << ans;
}