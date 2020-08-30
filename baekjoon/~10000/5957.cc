#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	stack<int> a, b, c;
	for(int i =n; i>=1; --i)
		a.push(i);
	int cmd, x;
	while (cin >> cmd >> x) {
		if (cmd == 1) {
			while (x > 0 && a.size()) {
				b.push(a.top());
				a.pop();
				x--;
			}
		} else {
			while (x > 0 && b.size()) {
				c.push(b.top());
				b.pop();
				x--;
			}
		}
	}
	while (c.size()) {
		cout << c.top() << '\n';
		c.pop();
	}
}