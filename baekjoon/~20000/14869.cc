#include <bits/stdc++.h>

using namespace std;
 
int n, m, s, e, t;
int a[3001][3001], b[3001];
int d[3001][3001], c[3001][3001];
 
struct pi{
    int v, t;
} mn[3001][3];
 
deque<pi> mq[3001];
 
int get_min(int a, int i) {
    if (mn[a][0].t != i && mn[a][0].t != b[i]) return mn[a][0].v;
    if (mn[a][1].t != i && mn[a][1].t != b[i]) return mn[a][1].v;
    return mn[a][2].v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s >> e >> t;
    for (int i =1; i<=n; ++i)
        for (int j =1; j<=m; ++j)
            cin >> a[i][j];
    for (int i =1; i<=n; ++i)
        cin >> b[i];
    for (int i =1; i<=n; ++i)
        for (int j =1; j<=m; ++j)
            c[i][j] = c[i][j - 1] + a[i][j];
    for (int i =1; i<=m; ++i){
        for (int j =1; j<=n; ++j){
            if (i >= s){
                int v = get_min(i - s, j) - c[j][i - s];
                while (!mq[j].empty() && mq[j].back().v >= v) mq[j].pop_back();
                mq[j].push_back({v, i - s});
            }
            while (!mq[j].empty() && mq[j].front().t < i - e) mq[j].pop_front();
            if (mq[j].empty() || mq[j].front().v == 1e9) d[i][j] = 1e9;
            else d[i][j] = mq[j].front().v + t + c[j][i];
        }
        for (int j =0; j<3; ++j) mn[i][j] = {(int)1e9, 0};
        for (int j =1; j<=n; ++j) if (d[i][j] < 1e9){
            int v = d[i][j];
            if (v < mn[i][0].v) {
                mn[i][2] = mn[i][1];
                mn[i][1] = mn[i][0];
                mn[i][0] = {v, j};
            } else if (v < mn[i][1].v) {
                mn[i][2] = mn[i][1];
                mn[i][1] = {v, j};
            } else if (v < mn[i][2].v) {
                mn[i][2] = {v, j};
            }
        }
    }
    int ans = 1e9;
    for (int i=1; i<=n; ++i){
        for (int j = m - e; j<m; ++j){
            int v = get_min(j, i);
            if (v == 1e9) continue;
            ans = min(ans, v + c[i][m] - c[i][j]);
        }
    }
    cout << ans;
}