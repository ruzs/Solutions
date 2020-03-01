#include <bits/stdc++.h>

using namespace std;

int n, a[11];
int rec(int msk) {
	if (__builtin_popcount(msk) == 2) return 0;
	int res = 0;
	for(int i =1; i<n - 1; ++i) {
		if (msk & (1 << i)) {
			int l = i - 1, r = i + 1;
			while(l > 0 && ~msk & (1 << l)) l--;
			while(r < n && ~msk & (1 << r)) r++;
			res = max(res, rec(msk & ~(1 << i)) + a[l] * a[r]);
		}
	}
	return res;
}
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	cout << rec((1 << n) - 1);
}