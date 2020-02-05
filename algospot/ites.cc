#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k, c = 0, s = 0;
	long long a = 1983;
	cin >> k >> n;
	queue<int> q;
	q.push(a);
	while(n--) {
		s += q.back();
		while (q.size() && s > k) s -= q.front(), q.pop();
		if (s == k) c++;
		q.push((a = (a * 214013 + 2531011) % (1LL<<32)) % 10000 + 1);
	}
	cout << c << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}