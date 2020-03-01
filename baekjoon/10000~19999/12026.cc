#include <bits/stdc++.h>

using namespace std;

int n, d[1001];
string s;
bool valid(char s, char e) {
	if (s == 'B' && e == 'O') return 1;
	if (s == 'O' && e == 'J') return 1;
	if (s == 'J' && e == 'B') return 1;
	return 0;
}
int dp(int x) {
	if (x == n - 1) return 0;
	int & ref = d[x];
	if (ref != -1) return ref;

	ref = 1e9;
	for(int i =x + 1; i<n; ++i) {
		if (valid(s[x], s[i]))
			ref = min(ref, dp(i) + (i - x) * (i - x));
	}
	return ref;
}
int main() {
	memset(d, - 1, sizeof d);
	cin >> n >> s;
	int ans = dp(0);
	cout << (ans < 1e9 ? ans : -1);
}