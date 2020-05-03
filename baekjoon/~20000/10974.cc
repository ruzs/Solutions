#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    do {
        for(int i : a) cout << i << ' ';
        cout << '\n';
    } while(next_permutation(a.begin(), a.end()));
}