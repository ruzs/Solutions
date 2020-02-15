#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, m, k, a[300005]{};
	cin >> n >> m >> k;
	for(int i =0; i<n; ++i) cin >> a[i];
	long long mx = 0, mxi = -1, ps = 0, cnt = 0;
	for(int i =0, j =0; i<n; ++i) {
		ps += a[i];
		cnt++;
		long long x = ps - k * ((cnt + m - 1) / m);
		if (mx < x) mx = x, mxi = i;
		if (ps < 0) {
			if (~mxi) {
				ps = mx;
				i = mxi;
				cnt = i - j + 1;
				while(j < i) {
					ps -= a[j++];
					cnt--;
					mx = max(mx, ps - k * ((cnt + m - 1) / m));
				}
			}
			ps = 0, cnt = 0, j = i + 1, mxi = -1;
		}
	}
	cout << mx;
}