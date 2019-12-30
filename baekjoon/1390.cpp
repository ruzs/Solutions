#include <bits/stdc++.h>

using namespace std;

int n, m = 1e6, d[301][64];
int dp(int x, int mask) {
	if (x > n) return 0;
	if (x == n) return mask == 0;

	int & ref = d[x][mask];
	if (ref != -1) return ref;
	
	switch(mask) {
		case 0: ref = (dp(x + 2, 20) + dp(x + 2, 17) + dp(x + 2, 5)) * 2 + dp(x + 1, 4) + dp(x + 1, 1) + dp(x + 1, 16); break;
		case 1: ref = dp(x + 1, 5) + dp(x + 1, 48) + dp(x + 1, 20) + dp(x + 3, 0); break;
		case 3: ref = dp(x + 1, 49) + dp(x + 2, 0) + dp(x + 4, 5); break;
		case 4: ref = dp(x + 3, 0) * 2; break;
		case 5: ref = dp(x + 1, 52) + dp(x + 2, 0) + dp(x + 3, 1) + dp(x + 4, 20); break;
		case 7: ref = dp(x + 2, 4) + dp(x + 2, 16); break;
		case 16: ref = dp(x + 1, 3) + dp(x + 1, 5) + dp(x + 1, 20) + dp(x + 3, 0); break;
		case 17: ref = dp(x + 1, 7) + dp(x + 1, 52) + dp(x + 2, 0) + dp(x + 4, 5) + dp(x + 4, 20); break;
		case 19: ref = dp(x + 2, 16) + dp(x + 2, 4) + dp(x + 3, 20); break;
		case 20: ref = dp(x + 1, 7) + dp(x + 2, 0) + dp(x + 3, 16) + dp(x + 4, 5); break;
		case 48: ref = dp(x + 1, 19) + dp(x + 2, 0) + dp(x + 4, 20); break;
		case 49: ref = dp(x + 2, 1) + dp(x + 2, 4) + dp(x + 3, 5); break;
		case 52: ref = dp(x + 2, 1) + dp(x + 2, 4); break;
		default: break;
	}
	return ref %= m;
}
int main() {
	memset(d, -1, sizeof d);
	cin >> n;
	cout << dp(0, 0);
}
