#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int & i : a) cin >> i;
    if (prev_permutation(a.begin(), a.end())) {
        for(int i : a) cout << i << ' ';
    } else {
        cout << -1;
    }
}