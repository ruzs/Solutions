#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> p = {0};
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		p.push_back(p.back() ^ x);
	}
	int ans = 0;
	while (m--) {
		int s, e;
		cin >> s >> e;
		ans ^= p[e] ^ p[s - 1];
	}
	cout << ans;
}