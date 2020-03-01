#include <bits/stdc++.h>

using namespace std;

int main() {
	int s, t, o = 0;
	cin >> s >> t;
	if (s == t) {
		cout << 0;
		return 0;
	}
	queue<pair<int, string>> q;
	q.push({s, ""});
	while(q.size()) {
		auto [a, c] = q.front(); q.pop();
		if (a == t) {
			cout << c;
			return 0;
		}
		if (a != 1 && 1LL * a * a <= 1e9)
			q.push({a * a, c + '*'});
		if (a + a <= 1e9)
			q.push({a + a, c + '+'});
		if (!o) q.push({1, c + '/'}), o = 1;
	}
	cout << -1;
}