#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, q[2000001], f = 0, b = 0;
	string opt;
	
	cin >> n;
	while(n--) {
		cin >> opt;
		if (opt == "push") {
			cin >> x;
			q[b++] = x;
		}
		else if (opt == "pop") {
			cout << (b == f ? -1 : q[f++]) << '\n';
		}
		else if (opt == "size") {
			cout << b - f << '\n';
		}
		else if (opt == "empty") {
			cout << (b == f) << '\n';
		}
		else if (opt == "front") {
			cout << (b == f ? -1 : q[f]) << '\n';
		}
		else if (opt == "back") {
			cout << (b == f ? -1 : q[b - 1]) << '\n';
		}
	}
}