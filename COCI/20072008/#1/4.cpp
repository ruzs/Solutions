#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint d[200][200], mod = 100000;
string s;
char open[] = "({[", close[] = ")}]";
lint go(int i, int j) {
	if (i > j) return 1;
	lint &ans = d[i][j];
	if (ans != -1) return ans;
	ans = 0;
	for (int k = i + 1; k <= j; k += 2) {
		for (int l = 0; l < 3; l++) {
			if ((s[i] == open[l] || s[i] == '?') && (s[k] == close[l] || s[k] == '?')) {
				ans += go(i + 1, k - 1) * go(k + 1, j);
				if (ans >= mod) ans = mod + ans % mod;
			}
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(d, -1, sizeof d);
	int n; cin >> n >> s;
	lint ans = go(0, n - 1);
	if (ans >= mod) {
		printf("%05lld\n", ans % mod);
	} else {
		printf("%lld\n", ans);
	}
}
