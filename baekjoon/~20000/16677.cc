#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int n;
	cin >> s >> n;
	string ans;
	pair<int, int> mx{};
	while(n--) {
		string a; int b;
		cin >> a >> b;
		int i =0;
		for(char c : a) {
			if (i < s.size() && c == s[i]) i++;
		}
		if (i == s.size()) {
			if (mx.first == 0 || mx.first * (a.size() - s.size()) < b * mx.second) {
				mx = {b, a.size() - s.size()};
				ans = a;
			}
		}
	}
	if (mx.first != 0) cout << ans;
	else cout << "No Jam";
}