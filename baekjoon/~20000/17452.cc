#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> pre(26, 1e9), suf(26, 1e9);
    int ans = 1e9;
    for(int i =0; i<n; ++i) {
        string s;
        cin >> s;
        for(int j =0; j<s.size(); ++j) {
            ans = min(ans, (int)s.size() - 1 - j + pre[s[j] - 'a']);
            ans = min(ans, suf[s[j] - 'a'] + j);
        }
        for(int j =0; j<s.size(); ++j) {
            pre[s[j] - 'a'] = min(pre[s[j] - 'a'], j);
            suf[s[j] - 'a'] = min(suf[s[j] - 'a'], (int)s.size() - 1 - j);
        }
    }
    if (ans < 1e9) cout << ans;
    else cout << -1;
}