#include <bits/stdc++.h>

using namespace std;

int m, n, k;
double s, a[50], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;
	for(int i =0; i<m; ++i) cin >> a[i], s += a[i];
	cin >> k;
	for(int i =0; i<m; ++i) {
		if (a[i] < k) continue;
		double t = 1.0;
		for(int j =0; j<k; ++j) {
			t *= (a[i] - j) / (s - j);
		}
		ans += t;
	}
	cout << setprecision(20) << ans;
}
