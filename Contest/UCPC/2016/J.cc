#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r;
    cin >> n >> r;
    map<string, int> city;
    for(int i =0; i<n; ++i) {
        string s;
        cin >> s;
        city[s] = i;
    }
    int m;
    cin >> m;
    vector<int> ord(m);
    for(int & i : ord) {
        string s;
        cin >> s;
        i = city[s];
    }
    int k;
    cin >> k;
    double c[100][100], cr[100][100];
    for(int i =0; i<n; ++i) for(int j =0; j<n; ++j) {
        if (i == j) c[i][j] = cr[i][j] = 0;
        else c[i][j] = cr[i][j] = 1e9;
    }        
    auto cost = [](string t, double x) {
        if (t == "Mugunghwa" || t == "ITX-Cheongchun" || t == "ITX-Saemaeul") return 0.;
        if (t == "V-Train" || t == "S-Train") return x / 2;
        return x;
    };
    while(k--) {
        string a, s, e;
        int u, v;
        double w;
        cin >> a >> s >> e >> w;
        u = city[s];
        v = city[e];
        c[u][v] = min(c[u][v], w);
        c[v][u] = min(c[v][u], w);
        w = cost(a, w);
        cr[u][v] = min(cr[u][v], w);
        cr[v][u] = min(cr[v][u], w);
    }
    for(int k =0; k<n; ++k) for(int i =0; i<n; ++i) for(int j =0; j<n; ++j) {
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
        cr[i][j] = min(cr[i][j], cr[i][k] + cr[k][j]);
    }
    double sum = 0, rsum = r;
    for(int i =1; i<m; ++i) {
        sum += c[ord[i - 1]][ord[i]];
        rsum += cr[ord[i - 1]][ord[i]];
    }
    if (sum > rsum) cout << "Yes";
    else cout << "No";
}