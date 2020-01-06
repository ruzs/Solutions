#include <bits/stdc++.h>
using namespace std;

int n, a[100001];
long long ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	sort(a, a + n);
	int g = a[n - 1] - a[n - 2];
	for(int i =n-1; i; --i) {
		a[i] -= a[i - 1];
		g = __gcd(g, a[i]);
	}
	for(int i =1; i<n; ++i) ans += a[i] / g - 1;
	cout << ans;
}
