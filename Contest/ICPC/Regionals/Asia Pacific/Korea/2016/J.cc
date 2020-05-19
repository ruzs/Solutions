#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for(int i =0; i<n; ++i) {
        int s, e;
        cin >> s >> e;
        a.push_back(minmax(s, e));
    }
    int d;
    cin >> d;
    sort(a.begin(), a.end(), [](auto a, auto b){return a.second < b.second;});
    debug(a);
    priority_queue<int> q;
    int ans = 0, r = 0;
    for(auto & [s, e] : a) {
        r = max(r, e);
        if (s >= e - d) q.push(-s);
        while(q.size()) {
            if (-q.top() < e - d) q.pop();
            else break;
        }
        ans = max<int>(ans, q.size());
    }
    cout << ans;
}