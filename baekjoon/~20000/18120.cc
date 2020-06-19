#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a;
    cin >> n >> a;
    vector<pair<double, double>> p(n), ps(n);
    for (int i = 0; i < n; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        p[i] = {hypot(x, y), w};
    }
	sort(p.begin(), p.end());
    ps[0].first = p[0].second;
    ps[0].second = p[0].first * p[0].second;
    for (int i = 1; i < n; ++i) {
        ps[i].first = ps[i - 1].first + p[i].second;
        ps[i].second = ps[i - 1].second + p[i].first * p[i].second;
    }
    double res = 0, tmp;
    for (int i = 0; i < n - 1; ++i) {
        if (p[i + 1].first < ps[i].first / (2 * a)) {
            tmp = -a * p[i + 1].first * p[i + 1].first +
                  p[i + 1].first * ps[i].first - ps[i].second;
            res = max(res, tmp);
        }
        if (p[i].first < ps[i].first / (2 * a)) {
            tmp = (ps[i].first * ps[i].first / (4 * a)) - ps[i].second;
            res = max(res, tmp);
        } else {
            continue;
        }
    }
    if (p[n - 1].first < ps[n - 1].first / (2 * a))
        tmp = (ps[n - 1].first * ps[n - 1].first) / (4 * a) - (ps[n - 1].second);
    res = max(res, tmp);
	
    cout.precision(20);
    cout << fixed << res;
}