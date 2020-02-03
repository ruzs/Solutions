#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d, e, s = 0;
	cin >> a >> b >> c >> d >> e;
	if (a < 0) s += -a * c + d;
	s += (b - max(a, 0)) * e;
	cout << s;
}