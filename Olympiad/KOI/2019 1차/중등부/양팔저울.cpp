#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int k, s;
vector<int> v;
bitset<2600000> u;
void rec(int n, int x) {
	if (n == k) {
		if (x >= 0 && x < s) u[x] = 1;
		return;
	}
	rec(n + 1, x);
	rec(n + 1, x - v[n]);
	rec(n + 1, x + v[n]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	v.resize(k);
	for(int & i : v) cin >> i, s += i;
	rec(0, 0);
	cout << s - u.count();
}
