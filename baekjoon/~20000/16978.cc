#include <bits/stdc++.h>

using namespace std;

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
    fenwick<long long> fw(n + 1);
    vector<int> a(n + 1);
    for(int i =1; i<=n; ++i) {
        cin >> a[i];
        fw.add(i, a[i]);
    }
    int m;
    cin >> m;
    vector<tuple<int, int, int, int>> q;
    int cnt1 = 0, cnt2 = 0;
    while (m--) {
        int o, k, i, j;
        cin >> o;
        if (o == 1) {
            cin >> i >> j;
            q.emplace_back(++cnt1, -1, i, j);
        } else {
            cin >> k >> i >> j;
            q.emplace_back(k, cnt2++, i, j);
        }
    }

    sort(q.begin(), q.end());
    vector<long long> ans(cnt2);
    for(auto & [k, qi, i, j] : q) {
        if (qi < 0) fw.add(i, j - a[i]), a[i] = j;
        else ans[qi] = fw.sum(j) - fw.sum(i - 1);
    }
    for(auto i : ans) cout << i << '\n';
}