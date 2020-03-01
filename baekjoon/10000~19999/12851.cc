#include <bits/stdc++.h>

using namespace std;

int n, m, d[150001];
queue<int> q;
int track(int a) {
	if (a == n) return 1;
	int res = 0;
	if (a < 100000) {
		if (d[a + 1] == d[a] - 1) res += track(a + 1);
	}
	if (a > 0) {
		if (d[a - 1] == d[a] - 1) res += track(a - 1);
	}
	if (a % 2 == 0) {
		if (d[a / 2] == d[a] - 1) res += track(a / 2);
	}
	return res;
}
int main() {
	cin >> n >> m;
	q.push(n);
	d[n] = 1;
	while(q.size()) {
		int a = q.front(); q.pop();
		if (a == m) break;
		if (a > 0) {
			if (!d[a - 1]) {
				d[a - 1] = d[a] + 1;
				q.push(a - 1);
			}
		}
		if (a < 100000) {
			if (!d[a + 1]) {
				d[a + 1] = d[a] + 1;
				q.push(a + 1);
			}
		}
		if (2 * a < 150000) {
			if (!d[a * 2]) {
				d[a * 2] = d[a] + 1;
				q.push(a * 2);
			}
		}
	}
	cout << d[m] - 1 << '\n' << track(m);
}