#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if (max(abs(a - e), abs(b - f)) < abs(c - e) + abs(d - f))
		puts("bessie");
	else if (max(abs(a - e), abs(b - f)) > abs(c - e) + abs(d - f))
		puts("daisy");
	else puts("tie");
}