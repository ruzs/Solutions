#include <bits/stdc++.h>

using namespace std;

int main() {
	int s, t;
	cin >> s >> t;
	queue<int> q;
	q.push(s);
	int cnt = 0, qs = q.size();
	while(qs--) {
		auto a = q.front(); q.pop();
		if (a == t) {
			cout << cnt + 1;
			return 0;
		}
		if (a * 2 <= t) q.push(a * 2);
		if (1LL * a * 10 + 1 <= t) q.push(a * 10 + 1);
		if (!qs) {
			cnt++;
			qs = q.size();
		}
	}
	cout << -1;
}