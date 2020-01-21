#include <bits/stdc++.h>

using namespace std;

long long n, d[10001];
long long dp(int n) {
	if (!n) return 1;
	if (d[n] != -1) return d[n];
	long long r = dp(n - 1) * n;
	while(r % 10 == 0) r /= 10;
	r %= 1000000000;
	return d[n] = r;
}
int main() {
	memset(d, -1, sizeof d);
	while(cin >> n) {
		cout.width(5);
		cout << n << " -> ";
		cout << dp(n) % 10 << '\n';
	}
}