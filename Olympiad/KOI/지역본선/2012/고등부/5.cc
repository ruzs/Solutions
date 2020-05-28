#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<int>> g(k), g2(k);
    vector<int> ind(k), ind2(k);
    for(int i =0; i<p; ++i) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g2[u].push_back(v);
        ind[u]++;
        ind2[v]++;
    }
    vector<int> mx(k), mn(k);
    priority_queue<int, vector<int>, greater<int>> pq, pq2;
    for(int i =0; i<k; ++i) {
        if (!ind[i]) {
            pq.push(i);
        }
        if (!ind2[i]) {
            pq2.push(i);
        }
    }
    int x = n - k;
    while(pq.size()) {
        int a = pq.top(); pq.pop();
        mx[a] = x++;
        for(int b : g[a]) {
            if (!--ind[b]) {
                pq.push(b);
            }
        }
    }
    x = k - 1;
    while(pq2.size()) {
        int a = pq2.top(); pq2.pop();
        mn[a] = x--;
        for(int b : g2[a]) {
            if (!--ind2[b]) {
                pq2.push(b);
            }
        }
    }
    auto pow = [](int a, auto e, int m) {
        long long r = 1, x = a % m;
        for (; e > 0; e >>= 1, x = x * x % m)
            if (e & 1) r = r * x % m;
        return r;
    };
    const int mod = 1000000007;
    long long ans = 0;
    for(int i =0; i<k; ++i) {
        ans = (ans + (mx[i] - mn[i]) * pow(n, i, mod)) % mod;
    }
    cout << (ans % mod + mod) % mod;
}