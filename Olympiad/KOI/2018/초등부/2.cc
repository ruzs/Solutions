#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	vector<int> a[5001];

	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> x >> y;
		a[y].push_back(x);
	}
	int s = 0;
	for(int i =1; i<=n; ++i) {
		if (a[i].size() < 1) continue;
		sort(a[i].begin(), a[i].end());
		s += abs(a[i][1] - a[i][0]) + abs(a[i][a[i].size() - 1] - a[i][a[i].size() - 2]);
		for(int j = 1; j+1<a[i].size(); ++j) {
			s += min(abs(a[i][j - 1] - a[i][j]), abs(a[i][j + 1] - a[i][j]));
		}
	}
	cout << s;
}