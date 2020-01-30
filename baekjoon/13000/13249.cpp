#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, a[12], t, ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	sort(a, a + n);
	cin >> t;
	for(int s =0; s<1<<n; ++s) {
		for(int i =0; i<n; ++i) {
			if (s & (1 << i)) {
				for(int j =i + 1; j<n; ++j) {
					if (~s & (1 << j)) {
						ans += (a[i] + t >= a[j] - t);
					}
				}
			}
		}
	}
	cout << ans * 1.0 / (1 << n);
}
