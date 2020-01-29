#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, x, a[400005];
	set<int> s;
	iota(a, a + 400005, 0);
	for(int i =0; i<400005; ++i) s.insert(i);
	cin >> n >> m;
	while(n--) {
		cin >> x;
		s.erase(a[x % m]);
		a[x % m] += m;
		cout << *s.begin() << '\n';
	}
}