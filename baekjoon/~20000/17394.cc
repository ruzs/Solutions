#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	bitset<100005> np;
	for(long long i = 3, j; i<100005; i+=2) {
		if (np[i]) continue;
		for(j = i * i; j<100005; j+=i) np[j] = 1;
	}
	int t;
	cin >> t;
	while(t--) [np] {
		int n, a, b;
		cin >> n >> a >> b;
		queue<int> q;
		bitset<1000005> v;
		for(int i =a; i<=b; ++i)
			if (i == 2 || i % 2 && !np[i]) {
				v[i] = 1;
				q.push(i);
			}
		int qs = q.size(), cnt = 0;
		while(qs--) {
			int a = q.front(); q.pop();
			if (a == n) {
				cout << cnt << '\n';
				return;
			}
			if (a * 3 + 2 < 1000005) {
				if (!v[a * 3]) {
					v[a * 3] = 1;
					q.push(a * 3);
				}
				if (!v[a * 3 + 1]) {
					v[a * 3 + 1] = 1;
					q.push(a * 3 + 1);
				}
				if (!v[a * 3 + 2]) {
					v[a * 3 + 2] = 1;
					q.push(a * 3 + 2);
				}
			}
			if (a * 2 + 1 < 1000005) {
				if (!v[a * 2]) {
					v[a * 2] = 1;
					q.push(a * 2);
				}
				if (!v[a * 2 + 1]) {
					v[a * 2 + 1] = 1;
					q.push(a * 2 + 1);
				}
			}
			if (a + 1 < 1000005 && !v[a + 1]) {
				v[a + 1] = 1;
				q.push(a + 1);
			}
			if (a - 1 > 0 && !v[a - 1]) {
				v[a - 1] = 1;
				q.push(a - 1);
			}
			if (!qs) {
				qs = q.size();
				cnt++;
			}
		}
		cout << -1 << '\n';
	} ();
}