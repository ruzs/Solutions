#include <bits/stdc++.h>
using namespace std;

int n, a[11], b, c, d, e, mx = -2e9, mn = 2e9;
void rec(int i, int s) {
	if (i == n) {
		if (mx < s) mx = s;
		if (mn > s) mn = s;
		return;
	}
	if (b) { b--; rec(i + 1, s + a[i]); b++; }
	if (c) { c--; rec(i + 1, s - a[i]); c++; }
	if (d) { d--; rec(i + 1, s * a[i]); d++; }
	if (e) { e--; rec(i + 1, s / a[i]); e++; }
}
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	cin >> b >> c >> d >> e;
	rec(1, a[0]);
	cout << mx << '\n' << mn;
}
