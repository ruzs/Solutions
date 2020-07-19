#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int l; cin >> l;
    int ans = 0;
    priority_queue<int> q;
    for(int i =1; i<n; ++i) {
        int x; cin >> x;
        q.push(x - l);
        ans += x - l;
        l = x;
    }
    while(--m) {
        ans -= q.top();
        q.pop();
    }
    cout << ans;
}