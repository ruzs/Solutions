#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, mx = 0, cnt = 0, a[300001];
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	sort(a, a + n);
	for(int i =1; i<=n; ++i) {
		if (a[n - i] + n < mx) break;
		a[n - i] += i;
		if (mx < a[n - i]) mx = a[n - i];
		cnt++;
	}
	cout << cnt;
}
