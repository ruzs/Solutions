#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> g(n);
    for(string & i : g) cin >> i;
    
    const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
    auto valid = [=](int y, int x)
        { return y >= 0 && x >= 0 && y < n && x < n; };
    
    priority_queue<tuple<int, int, int>> pq;
    pq.emplace(0, 0, 0);
    int d[51][51];
    memset(d, 64, sizeof d);
    d[0][0] = 0;
    while(pq.size()) {
        auto [c, y, x] = pq.top(); pq.pop();
        if (d[y][x] < -c) continue;
        for(int w =0; w<4; ++w) {
            int ny = y + dy[w], nx = x + dx[w];
            if (!valid(ny, nx)) continue;
            int nc = -c + (g[ny][nx] == '0');
            if (d[ny][nx] > nc) {
                d[ny][nx] = nc;
                pq.emplace(-nc, ny, nx);
            }
        }
    }
    cout << d[n - 1][n - 1];
}