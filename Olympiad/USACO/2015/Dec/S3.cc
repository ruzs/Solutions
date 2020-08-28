#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> p = {{0, 0, 0}};
	for(int i =0; i<n; ++i) {
		int x; cin >> x;
		p.push_back(p.back());
		p.back()[x - 1]++;
	}
	while (m--) {
		int s, e;
		cin >> s >> e;
		for(int i =0; i<3; ++i) {
			cout << p[e][i] - p[s - 1][i] << ' ';
		}
		cout << '\n';
	}
}