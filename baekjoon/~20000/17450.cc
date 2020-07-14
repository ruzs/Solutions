#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    struct S {
        int p, g;
        char name;
        bool operator < (S & b) const {
            return g * b.p < b.g * p;
        }
    };
    vector<S> a(3);
    a[0].name = 'S';
    a[1].name = 'N';
    a[2].name = 'U';
    for(S & i : a) {
        cin >> i.p >> i.g;
        i.p *= 10;
        i.g *= 10;
        if (i.p >= 5000) i.p -= 500;
    }
    cout << max_element(a.begin(), a.end())->name;
}