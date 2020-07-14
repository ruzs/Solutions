#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto & i : a) cin >> i;
    reverse(a.begin(), a.end());
    long long v = 0;
    for(auto & i : a) {
        i = ((v - 1) / i + 1) * i;
        v = i;
    }
    cout << v;
}