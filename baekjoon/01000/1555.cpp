#include <bits/stdc++.h>
using namespace std;

int n, a[6], mx, mn = 1e9;
set<int> d[1<<6];
bool isPrime(int x) {
	if (x == 2) return 1;
	if (x < 2 || x % 2 == 0) return 0;
	for(int i =3; i*i<=x; i+=2) {
		if (x % i == 0) return 0;
	}
	return 1;
}
void dp(int s) {
	if (d[s].size()) return;
	for(int i =0; i<s; ++i) {
		int a =  i & s;
		int b = ~i & s;
		if (!a || !b) continue;

		dp(a);
		dp(b);
		
		for(int j : d[a]) {
			for(int k : d[b]) {
				if (j) d[s].insert(k / j);
				if (k) d[s].insert(j / k);
				d[s].insert(j + k);
				d[s].insert(j - k);
				d[s].insert(k - j);
				d[s].insert(j * k);
			}
		}
	}
	return;
}
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> a[i];
		d[1<<i].insert(a[i]);
	}
	
	dp((1 << n) - 1);

	for(int i : d[(1<<n) - 1]) {
		if (isPrime(i)) {
			if (mx < i) mx = i;
			if (mn > i) mn = i;
		}
	}
	if (mx) cout << mn << '\n' << mx;
	else cout << -1;
}
