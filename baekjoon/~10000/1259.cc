#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while(cin >> s) {
		if (s == "0") break;
		function<bool(int, int)> isPalindrome = [&](int l, int r) {
			if (l >= r) return true;
			if (s[l] == s[r]) return isPalindrome(l + 1, r - 1);
			return false;
		};
		if (isPalindrome(0, s.size() - 1)) cout << "yes\n";
		else cout << "no\n";
	}
}