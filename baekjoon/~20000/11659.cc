#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> p = {0};
	while (n--) {
		int x; cin >> x;
		p.push_back(p.back() + x);
	}
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << p[j] - p[i - 1] << '\n';
	}
}