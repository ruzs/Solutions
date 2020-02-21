#include <bits/stdc++.h>

using namespace std;

long long f(long long a) {
	if (a <= 2) return a;
	return a * (a - 1) / 2;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char s[100005];
	long long ab[26]{};
	cin >> s;
	long long ans = 1, cnt = 0;
	for(int i =0; s[i]; ++i) {
		ab[s[i] - 'a']++;
		cnt++;
		if (s[i] != s[i + 1]) {
			ans = max(ans * f(cnt), f(ab[s[i] - 'a']));
			cnt = 0;
		}
	}
	cout << ans;
}