#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, n, a;
	cin >> x >> n;
	multiset<int> s = {0, x}, t = {x};
	while(n--) {
		cin >> a;
		auto lb = s.lower_bound(a);
		t.erase(t.find(*lb - *prev(lb)));
		t.insert(a - *prev(lb));
		t.insert(*lb - a);
		s.insert(a);
		cout << *prev(t.end()) << ' ';
	}
}