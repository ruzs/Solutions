#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	if ((a + b) & 1) cout << -1;
	else {
		tie(a, b) = minmax((a + b) / 2, a - (a + b) / 2);
		if (a < 0) cout << -1;
		else cout << b << ' ' << a;
	}
}