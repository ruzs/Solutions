#include <bits/stdc++.h>

using namespace std;

int U, ans = 1e9, v[5001];
void go(int c, int n, int b, int u) {
	if (b && v[b]) return;
	v[b] = 1;
	if (b + u <= n) return ans = min(ans, c), void(0);
	if (n <= 0 || c > 5000) return;
	for(int i =0; i<=min(b, n); ++i) {
		int r = n - i;
		if (r > u) continue;
		go(c + 1, n - (u - r), b - i, u - r + (b - i ? U : 0));
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, b;
	cin >> n >> b >> U;
	if (b > n) go(2, n, b - n, U);
	else ans = 1;
	cout << (ans < 1e9 ? ans : -1);
}