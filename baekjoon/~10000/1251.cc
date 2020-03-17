#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, ans(50, 'z');
	cin >> s;
	for(int i =2; i<(int)s.size(); ++i) {
		for(int j =1; j<i; ++j) {
			string t = s;
			reverse(t.begin(), t.begin() + j);
			reverse(t.begin() + j, t.begin() + i);
			reverse(t.begin() + i, t.end());
			ans = min(ans, t);
		}
	}
	cout << ans;
}