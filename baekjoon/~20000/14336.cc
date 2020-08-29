#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;
	for(int t =1; t<=tt; ++t) {
		int n, m;
		cin >> n >> m;
		vector<long long> p = {0};
		for(int i =0; i<n; ++i) {
			int x; cin >> x;
			p.push_back(p.back() + x);
		}
		vector<int> a;
		for(int i =1; i<=n; ++i) {
			for(int j =i; j<=n; ++j) {
				a.push_back(p[j] - p[i - 1]);
			}
		}
		sort(a.begin(), a.end());
		p = {0};
		for(int i : a) p.push_back(p.back() + i);
		cout << "Case #" << t << ":\n";
		while (m--) {
			int i, j;
			cin >> i >> j;
			cout << p[j] - p[i - 1] << '\n';
		}
	}
}