#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<pair<int, int>> pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i =0; i<n; ++i) {
        int t, s;
        cin >> t >> s;
        pq.push({s, t});
    }
    int ans = 1e9, l = 1e9;
    while(pq.size()) {
        auto [s, t] = pq.top();
        pq.pop();
        l = min(l, s) - t;
        ans = min(ans, l);
    }
    if (ans < 0) cout << -1;
    else cout << ans;
}