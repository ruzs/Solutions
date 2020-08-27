#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int n = s.size();
	long long ans = 0, cnt = 0;
	for(int i =1; i<s.size(); ++i) {
		if (s[i] == s[i - 1]) {
			if (s[i] == ')') {
				ans += cnt;
			} else {
				cnt++;
			}
		}
	}
	cout << ans;
}