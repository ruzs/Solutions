#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for(int & i : a) {
        cin >> i;
        i = mp.count(i) ? mp[i] : mp[i] = mp.size();
    }
    int m;
    cin >> m;
    struct Q {
        int s, e, qi, srt;
        bool operator < (Q & b) const {
            return srt < b.srt || srt == b.srt && e < b.e;
        }
    };
    vector<Q> q(m);
    for(int i =0; i<m; ++i) {
        int s, e;
        cin >> s >> e;
        q[i] = {s-1, e-1, i, (s-1)/1000};
    }
    sort(q.begin(), q.end());
    vector<int> ans(m), cnt(mp.size());
    int l = 0, r = -1, c = 0;
    for(auto & [s, e, qi, x] : q) {
        while(l < s) if (!--cnt[a[l++]]) c--;
        while(l > s) if (!cnt[a[--l]]++) c++;
        while(r < e) if (!cnt[a[++r]]++) c++;
        while(r > e) if (!--cnt[a[r--]]) c--;
        ans[qi] = c;
    }
    for(int i : ans) cout << i << '\n';
}