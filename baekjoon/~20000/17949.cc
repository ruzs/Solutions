#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int n;
    cin >> s >> n;
    for(int i =0, j =0; i<n; ++i) {
        string t;
        cin >> t;
        auto dec = [](string s) {
            long long r = 0;
            for(char c : s) {
                if (isdigit(c)) r = r * 16 + (c & 15);
                else r = r * 16 + (c - 'a' + 10);
            }
            return r;
        };
        if (t == "char") cout << dec(s.substr(j, 2)) << ' ', j += 2;
        else if (t == "int") cout << dec(s.substr(j, 8)) << ' ', j += 8;
        else cout << dec(s.substr(j, 16)) << ' ', j += 16;
    }
}