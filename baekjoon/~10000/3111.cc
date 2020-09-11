#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string t, s;
    cin >> t >> s;
    string F = "", B = "";
    int tn = t.size();
    int l = 0, r = s.size() - tn;
    while (1) {
        while (l < r && t != s.substr(l, tn)) {
            F += s[l++];
        }
        if (l <= r && t == s.substr(l, tn)) {
            l += tn;
            for (int i = 0; F.size() && i < tn; i++) {
                s[--l] = F.back();
                F.pop_back();
            }
            for (int i = 0; B.size() && i < tn; i++) {
                s[r++ + tn] = B.back();
                B.pop_back();
            }
        } else {
            break;
        }
        while (l < r && t != s.substr(r, tn)) {
            B += s[--r + tn];
        }
        if (l <= r && t == s.substr(r, tn)) {
            r -= tn;
            for (int i = 0; F.size() && i < tn; i++) {
                s[--l] = F.back();
                F.pop_back();
            }
            for (int i = 0; B.size() && i < tn; i++) {
                s[r++ + tn] = B.back();
                B.pop_back();
            }
        } else {
            break;
        }
    }
    while (F.size()) {
        s[--l] = F.back();
        F.pop_back();
    }
    while (B.size()) {
        s[r++ + tn] = B.back();
        B.pop_back();
    }
    for (int i = l; i < r + tn; i++) {
        cout << s[i];
    }
}