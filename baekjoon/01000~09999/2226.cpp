#include <bits/stdc++.h>
using namespace std;
using bint = string;
int n;
bint d[1001];
bint operator + (const bint & a, const bint & b) {
	if (a.size() > b.size()) return b + a;
	bint r = b + "0";
	for(int i =0; i<b.size(); ++i) {
		if (i < a.size()) r[i] += a[i] & 15;
		if (r[i] > '9') {
			r[i] -= 10;
			r[i + 1]++;
		}
	}
	while(r.size() > 1 && r.back() == '0') r.pop_back();
	return r;
}
int main() {
	cin >> n;
	d[1] = "0";
	d[2] = "1";
	for(int i =3; i<=n; ++i) {
		bint t = d[i - 2] + d[i - 2];
		d[i] = d[i - 1] + t;
	}
	reverse(d[n].begin(), d[n].end());
	cout << d[n];
}
