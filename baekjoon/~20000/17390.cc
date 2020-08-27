#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), p = {0};
	for(int & i : a) cin >> i;
	sort(a.begin(), a.end());
	for(int i : a) p.push_back(p.back() + i);
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << p[e] - p[s - 1] << '\n';
	}
}