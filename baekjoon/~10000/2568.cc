#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i =0; i<n; ++i) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [](auto a, auto b){return a.second < b.second;});
    vector<set<int>> b(n + 1);
    vector<int> v = {(int)-1e9};
    for(auto & [f, s] : a) {
        if (v.back() < f) {
            v.push_back(f);
            b[v.size() - 1].insert(f);
        } else {
            auto lb = lower_bound(v.begin(), v.end(), f);
            *lb = f;
            b[lb - v.begin()].insert(f);
        }
    }
    int l = 1e9;
    for(int i =v.size() - 1; i>0; --i) {
        auto lb = prev(b[i].lower_bound(l));
        l = *lb;
        b[i].erase(lb);
    }
    set<int> ans;
    for(int i = 1; i<v.size(); ++i) for(int j : b[i]) ans.insert(j);
    cout << ans.size() << '\n';
    for(int i : ans) cout << i << '\n';
}