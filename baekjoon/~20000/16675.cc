#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	char a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == b) {
		if (a == 'S') {
			if (c == 'R' || d == 'R') {
				cout << "TK";
			} else if (c == 'P' && d == 'P') {
				cout << "MS";
			} else {
				cout << "?";
			}
		} else if (a == 'R') {
			if (c == 'P' || d == 'P') {
				cout << "TK";
			} else if (c == 'S' && d == 'S') {
				cout << "MS";
			} else {
				cout << "?";
			}
		} else if (a == 'P') {
			if (c == 'S' || d == 'S') {
				cout << "TK";
			} else if (c == 'R' && d == 'R') {
				cout << "MS";
			} else {
				cout << "?";
			}
		}
	} else if (c == d) {
		if (c == 'S') {
			if (a == 'R' || b == 'R') {
				cout << "MS";
			} else if (a == 'P' && b == 'P') {
				cout << "TK";
			} else {
				cout << "?";
			}
		} else if (c == 'R') {
			if (a == 'P' || b == 'P') {
				cout << "MS";
			} else if (a == 'S' && b == 'S') {
				cout << "TK";
			} else {
				cout << "?";
			}
		} else if (c == 'P') {
			if (a == 'S' || b == 'S') {
				cout << "MS";
			} else if (a == 'R' && b == 'R') {
				cout << "TK";
			} else {
				cout << "?";
			}
		}
	} else {
		cout << "?";
	}
}