#include <bits/stdc++.h>

using namespace std;

void test() {
	int n, x, y;
	cin >> n >> x >> y;
	if (x > y) swap(x, y);
	cout << y - 1 - min(y - 1, (n - x - 1)) + 1 << ' ' << min(n, x + y - 1) << '\n';
}
int main() {
	int t;
	cin >> t;
	while(t--) test();
}