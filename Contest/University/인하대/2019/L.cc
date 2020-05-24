#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> st;
vector<int> rmq;
int N, M;

void build(vector<int> & a, int i = 1, int l = 0, int r = N) {
    if (l == r) {
        st[i] = {a[l]};
    } else {
        int m = l + r >> 1;
        build(a, i << 1, l, m);
        build(a, i << 1 | 1, m + 1, r);
        auto & L = st[i << 1];
        auto & R = st[i << 1 | 1];
        merge(L.begin(), L.end(), R.begin(), R.end(), back_inserter(st[i]));
    }
}

int sum(int s, int e, int x, int i = 1, int l = 0, int r = N) {
    if (e < l || r < s) return 0;
    if (s <= l && r <= e) return st[i].end() - lower_bound(st[i].begin(), st[i].end(), x);
    int m = l + r >> 1;
    return sum(s, e, x, i << 1, l, m) + sum(s, e, x, i << 1 | 1, m + 1, r);
}

void update(int p, int x, int i = 1, int l = 0, int r = M) {
    if (l == r) {
        rmq[i] = x;
    } else {
        int m = l + r >> 1;
        if (p <= m) update(p, x, i << 1, l, m);
        else update(p, x, i << 1 | 1, m + 1, r);
        rmq[i] = max(rmq[i << 1], rmq[i << 1 | 1]);
    }
}

int last(int s, int e, int i = 1, int l = 0, int r = M) {
    if (s > e || e < l || r < s) return -1;
    if (s <= l && r <= e) return rmq[i];
    int m = l + r >> 1;
    return max(last(s, e, i << 1, l, m), last(s, e, i << 1 | 1, m + 1, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> AB(n);
    vector<int> ord, K(m);
    for(auto & i : AB) {
        cin >> i.first >> i.second;
        ord.push_back(i.first);
        ord.push_back(i.second);
    }
    for(int & i : K) {
        cin >> i;
        ord.push_back(i);
    }

    sort(ord.begin(), ord.end());
    ord.erase(unique(ord.begin(), ord.end()), ord.end());
    N = m - 1; M = ord.size();
    st.resize(N << 2);
    rmq.resize(M << 2, -1);
    for(int i =0; i<m; ++i) {
        update(lower_bound(ord.begin(), ord.end(), K[i]) - ord.begin(), i);
    }
    build(K);
    
    long long ans = 0;
    for(auto & i : AB) {
        auto [smaller, bigger] = minmax(i.first, i.second);
        int x = last(
            lower_bound(ord.begin(), ord.end(), smaller) - ord.begin(),
            lower_bound(ord.begin(), ord.end(), bigger) - ord.begin() - 1);
        
        if (x < 0) {
            int f = sum(0, N, bigger);
            if (f & 1) ans += i.second;
            else ans += i.first;
        } else {
            int f = sum(x, N, bigger);
            if (f & 1) ans += smaller;
            else ans += bigger;
        }
    }
    cout << ans;
}