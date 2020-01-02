#include <bits/stdc++.h>

using namespace std;

const int mod = 1e7 + 3;
int n, a[101], d[2][100001];
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =1; i<=n; ++i) cin >> a[i];
	d[0][0] = 1;
	for(int i =1, x =1; i<=n; ++i, x^=1) {
		memset(d[x], 0, sizeof d[x]);
		for(int j =0; j<=100000; ++j) {
			if (d[x^1][j]) {
				int & ref = d[x][gcd(j, a[i])];
				ref += d[x^1][j];
				ref %= mod;
				d[x][j] += d[x^1][j];
				d[x][j] %= mod;
			}
		}
	}
	cout << d[n&1][1];
}
