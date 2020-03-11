#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		auto bfs = [](int a) {
			queue<pair<int, string>> q;
			bitset<20000> bs;
			q.push({1, "1"});
			int qs = q.size(), cnt = 0;
			while(q.size()) {
				auto [r, s] = q.front(); q.pop();
				if (!r) return s;
				if (!bs[(r * 10 % a) % a]) {
					bs[(r * 10 % a) % a] = 1;
					q.push({ (r * 10 % a) % a, s + '0' });
				}
				if (!bs[(r * 10 % a + 1) % a]) {
					bs[(r * 10 % a + 1) % a] = 1;
					q.push({ (r * 10 % a + 1) % a, s + '1' });
				}
			}
			return string("BRAK");
		};
		cout << bfs(n) << '\n';
	}
}