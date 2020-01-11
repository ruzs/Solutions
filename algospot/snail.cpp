#include <bits/stdc++.h>
using namespace std;

int N, M;
double d[1001][1001];
bool c[1001][1001];
double dp(int n, int m) {
	if (n >= N || m == M) return n >= N ? 1.0 : 0.0;
	if (c[n][m]) return d[n][m];
	c[n][m] = 1;
	return d[n][m] = 0.75 * dp(n + 2, m + 1) + 0.25 * dp(n + 1, m + 1);
}
int main() {
	int T; cin >> T;
	while(T--) {
		cin >> N >> M;
		memset(c, 0, sizeof c);
		cout << setprecision(30) << dp(0, 0) << '\n';
	}
}
