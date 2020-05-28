#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
template <typename T>
struct fenwick {
    vector<T> a;
    fenwick(int n) { a.resize(n); }

    void add(int p, T x) {
        do a[p] += x;
        while ((p += p & -p) < a.size());
    }
    T sum(int p) {
        T r{};
        do r += a[p];
        while (p -= p & -p);
        return r;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(auto & i : a) {
        cin >> i.second >> i.first;
        i.second += 200005;
    }
    sort(a.rbegin(), a.rend());
    long long ans = 0;
    fenwick<int> fw(1<<19);
    for(int i =0, j =0; j<n; ++j) {
        if (j > 0 && a[j].first != a[j - 1].first) {
            while(i < j) fw.add(a[i].second, 1), i++;
        }
        ans = (ans + 1ll * fw.sum(a[j].second - 1) * (fw.sum(400005) - fw.sum(a[j].second))) % mod;
    }
    cout << ans;
}