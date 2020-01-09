#include <bits/stdc++.h>
using namespace std;

int n, a[20][20], d[1 << 20];
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<n; ++j) {
			cin >> a[i][j];
		}
	}
	for(int s =1; s+1<1<<n; ++s) {
		d[s] = d[s - (s & -s)];
		int j = __builtin_ctz(s);
		for(int c =s; c -= c & -c;) {
			int k = __builtin_ctz(c);
			d[s] += a[j][k] + a[k][j];
		}
	}
	int ans = 1e9, all = (1 << n) - 1;
	for(int s =1; s<all; ++s) {
		ans = min(ans, abs(d[s] - d[s ^ all]));
	}
	cout << ans;
}
