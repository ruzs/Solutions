#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	for(int i =1; i<=n; ++i) cin >> v[i];
	while(m--) {
		int cmd, a, b, c, d;
		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b;
			long long sum = 0;
			for(int i =a; i<=b; ++i) sum += v[i];
			cout << sum << '\n';
			swap(v[a], v[b]);
		} else {
			cin >> a >> b >> c >> d;
			long long sum1 = 0, sum2 = 0;
			for(int i =a; i<=b; ++i) sum1 += v[i];
			for(int i =c; i<=d; ++i) sum2 += v[i];
			cout << sum1 - sum2 << '\n';
		}
	}
}