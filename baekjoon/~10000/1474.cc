#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, sum = 0;
	cin >> n >> m;
	string s[100];
	for(int i =0; i<n; ++i) cin >> s[i], sum += s[i].size();
	m -= sum;
	for(int i =0; i<n - 1; ++i) {
		s[i] += string(m / (n - 1), '_');
	}
	m %= n - 1;
	for(int i =0; m && i<n - 1; ++i) {
		if (i + m == n - 1 || s[i + 1][0] > 'Z') s[i] += '_', m--;
	}
	for(int i =0; i<n; ++i) cout << s[i];
}