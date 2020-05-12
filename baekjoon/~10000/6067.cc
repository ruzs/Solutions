#include <bits/stdc++.h>

using namespace std;

int n, m, g[700][700];
constexpr int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
auto valid(int y, int x) {
    return y >= 0 && x >= 0 && y < n && x < m;
};

bool v[700][700];
bool dfs(int y, int x) {
    v[y][x] = 1;
    bool res = true;
    for(int w =0; w<8; ++w) {
        int ny = y + dy[w], nx = x + dx[w];
        if (valid(ny, nx) && g[ny][nx] == g[y][x] && !v[ny][nx])
            res &= dfs(ny, nx);
    }
    for(int w =0; w<8; ++w) {
        int ny = y + dy[w], nx = x + dx[w];
        if (valid(ny, nx) && g[ny][nx] > g[y][x]) return false;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i =0; i<n; ++i) for(int j =0; j<m; ++j)
        cin >> g[i][j];
    int ans = 0;
    for(int i =0; i<n; ++i) for(int j =0; j<m; ++j) {
        if (!v[i][j] && dfs(i, j)) ans++;
    }
    cout << ans;
}