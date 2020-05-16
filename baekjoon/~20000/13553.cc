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

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    fenwick<int> fw(100005);
    for(int i =1; i<=n; ++i) cin >> a[i];
    int m;
    cin >> m;
    const int rt = 320;
    struct query {
        int l, r, idx;
        bool operator < (query & b) const {
            return make_pair(l / rt, r) < make_pair(b.l / rt, b.r);
        }
    };
    vector<query> q(m);
    vector<long long> ans(m);
    for(int i =0; i<m; ++i) {
        int s, e;
        cin >> s >> e;
        q[i] = {s, e, i};
    }
    sort(q.begin(), q.end());
    int ls = 1, le = 0;
    long long cnt = 0;
    auto add = [&](int x, int c) {
        fw.add(x, c);
    };
    for(auto & [s, e, qi] : q) {
        while(ls < s) {
            fw.add(a[ls], -1);
            cnt -= fw.sum(min(100000, a[ls] + k)) - fw.sum(max(0, a[ls] - k - 1));
            ls++;
        }
        while(le < e) {
            le++;
            cnt += fw.sum(min(100000, a[le] + k)) - fw.sum(max(0, a[le] - k - 1));
            fw.add(a[le], 1);
        }
        while(ls > s) {
            ls--;
            cnt += fw.sum(min(100000, a[ls] + k)) - fw.sum(max(0, a[ls] - k - 1));
            fw.add(a[ls], 1);
        }
        while(le > e) {
            fw.add(a[le], -1);
            cnt -= fw.sum(min(100000, a[le] + k)) - fw.sum(max(0, a[le] - k - 1));
            le--;
        }
        ans[qi] = cnt;
    }
    for(long long i : ans) cout << i << '\n';
}