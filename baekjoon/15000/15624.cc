#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, p = 0, np = 1;
	cin >> n;
	while(n--) {
		int t = np;
		np += p;
		np %= 1000000007;
		p = t;
	}
	cout << p;
}