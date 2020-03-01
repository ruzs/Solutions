#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = 0, j = 0, m = 100000;
	for(int i =0; i < 4; ++i) {
		int x = a * d + b * c, y = c * d;
		if (x * m > j * y) m = y, j = x, ans = i;
		int t = a;	
		a = c;
		c = d;
		d = b;
		b = t;
	}
	cout << ans;
}