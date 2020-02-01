#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; long long cp = 1, p = 0, np = 1;
	cin >> n;
	while(--n) {
		long long t = np;
		np += p;
		cp = p;
		p = t;
	}
	cout << (cp + 2 * p + np) * 2;
}