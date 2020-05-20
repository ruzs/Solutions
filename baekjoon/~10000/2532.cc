#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i =0; i<n; ++i) {
        int x, s, e;
        cin >> x >> s >> e;
        a[x - 1] = {s, e};
    }
    sort(a.begin(), a.end(), [](auto a, auto b){
        return a.first > b.first || a.first == b.first && a.second < b.second;
    });
    vector<int> lis = {-1};
    for(int i =0; i<n; ++i) {
        if (i && a[i] == a[i - 1]) continue;
        int e = a[i].second;
        if (lis.back() <= e) lis.push_back(e);
        else *upper_bound(lis.begin(), lis.end(), e) = e;
    }
    cout << lis.size() - 1;
}