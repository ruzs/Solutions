#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a[200005], idx = 0;
	cin >> n >> m;
	for(int i =0; i<n; ++i) cin >> a[i];

	auto find = [&](int x) { return (idx + x + n) % n; };
	while(m--) {
		int opt, b, c;
		cin >> opt;
		if (opt == 1) {
			cin >> b >> c;
			a[find(b - 1)] += c;
		}
		else if (opt == 2) {
			cin >> b;
			idx = find(-b);
		}
		else if (opt == 3) {
			cin >> b;
			idx = find(b);
		}
	}
	for(int i =idx; i<n; ++i) cout << a[i] << ' ';
	for(int i =0; i<idx; ++i) cout << a[i] << ' ';
}