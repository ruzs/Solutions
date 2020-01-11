#include <bits/stdc++.h>
using namespace std;

const int m = 1000000007;
void solve() {
	int n; cin >> n;
	int p = 0, np = 1;
	while(n--) {
		int t = p;
		p = np;
		np = (np + t) % m;
	}
	cout << np << '\n';
}
int main() {
	int n; cin >> n;
	while(n--) solve();
}
