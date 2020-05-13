#include <bits/stdc++.h>

using namespace std;

#define N 1505
int n, x, y, s, e, a[N][N];
long long sum = 0;
char c;
struct fwt {
    int a[N];
    void upd(int p, int v) {
        do a[p] += v;
        while((p += p & -p) < N);
    }
    int qry(int p) {
        int r = 0;
        do r += a[p];
        while(p -= p & -p);
        return r;
    }
} fw[N];

int dp(int i, int j, int x = -1) {
    if (~x) {
        fw[j].upd(i, x);
        fw[j].upd(i + 1, -x);
        return x;
    }
    return fw[j].qry(i);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i =1; i<=n; ++i) for(int j =1; j<=n; ++j) cin >> a[i][j];
    for(int i =1; i<=n; ++i) for(int j =1; j<=n; ++j) sum += dp(i, j, max(dp(i, j - 1), dp(i - 1, j)) + a[i][j]);

    cout << sum << '\n';
    for(int i =1; i<=n; ++i) {
        cin >> c >> y >> x;
        s = y;
        e = y;
        if (c == 'U') {
            while(s <= e) {
                while(e < n && dp(e, x) >= dp(e + 1, x - 1)) e += 1;
                fw[x].upd(s, 1); fw[x].upd(e + 1, -1);
                sum += e - s + 1;
                x++;
                if (x > n) break;
                while(s <= e && dp(s, x - 1) <= dp(s - 1, x)) s += 1;
            }
        } else {
            while(s <= e) {
                while(e < n && dp(e, x) > dp(e + 1, x - 1)) e += 1;
                fw[x].upd(s, -1); fw[x].upd(e + 1, 1);
                sum -= e - s + 1;
                x++;
                if (x > n) break;
                while(s <= e && dp(s, x - 1) < dp(s - 1, x)) s += 1;
            }
        }
        cout << sum << '\n';
    }
}