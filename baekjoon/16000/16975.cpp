#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, i, j, k;
long long fw[N];
void u(int p, int x) {
	while(p < N) fw[p] += x, p += p & -p;
}
auto q(int p) {
	long long r = fw[p];
	while(p -= p & -p) r += fw[p];
	return r;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =1; i<=n; ++i) {
		cin >> k;
		u(i, k); u(i + 1, -k);
	}
	cin >> m;
	while(m--) {
		cin >> i;
		if (i == 1) {
			cin >> i >> j >> k;
			u(i, k); u(j + 1, -k);
		} else {
			cin >> k;
			cout << q(k) << '\n';
		}
	}
}
