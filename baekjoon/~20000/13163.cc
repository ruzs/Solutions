#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        cout << "god";
        int l = -1;
        for(int i =0; i<s.size(); ++i) {
            if (s[i] == ' ') {
                if (l == -1) l = i + 1;
                else cout << s.substr(l, i - l), l = i + 1;
            }
        }
        cout << s.substr(l) << '\n';
    }
}