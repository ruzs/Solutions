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
			if (a == 1) {
				cout << "1\n";
				return;
			}
			queue<int> q;
			vector<int> f(a, -1);
			vector<char> d(a, -1);
			q.push(1);
			d[1] = '1';
			int qs = q.size(), cnt = 0;
			while(q.size()) {
				auto r = q.front(); q.pop();
				if (!r) {
					string ans{};
					while(~r) {
						ans += d[r];
						r = f[r];
					}
					for(int i =ans.size() - 1; ~i; --i) cout << ans[i];
					cout << '\n';
					return;
				}
				int nr = (r * 10 % a) % a;
				if (!~d[nr]) {
					d[nr] = '0';
					f[nr] = r;
					q.push(nr);
				}
				nr = (r * 10 % a + 1) % a;
				if (!~d[nr]) {
					d[nr] = '1';
					f[nr] = r;
					q.push(nr);
				}
			}
			cout << "BRAK\n";
		};
		bfs(n);
	}
}