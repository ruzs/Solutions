#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> row(n), col(n);
		for(int i =0; i<n; ++i) {
			for(int j =0; j<n; ++j) {
				int x; cin >> x;
				row[i] += x;
				col[j] += x;
			}
		}
		while (m--) {
			int y1, x1, y2, x2, v;
			cin >> y1 >> x1 >> y2 >> x2 >> v;
			for(int i =y1-1; i<y2; ++i)
				row[i] += (x2 - x1 + 1) * v;
			for(int i =x1-1; i<x2; ++i)
				col[i] += (y2 - y1 + 1) * v;
		}
		for(int i : row) cout << i << ' ';
		cout << '\n';
		for(int i : col) cout << i << ' ';
		cout << '\n';
	}
}