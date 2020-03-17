#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, a, b;
	cin >> x >> y >> a >> b;
	set<int> s;
	for(int i =0; i<=10000; ++i) {
		s.insert(a);
		a += x;
	}
	for(int i =0; i<=10000; ++i) {
		if (s.count(b)) {
			cout << b;
			return 0;
		}
		b += y;
	}
	cout << -1;
}