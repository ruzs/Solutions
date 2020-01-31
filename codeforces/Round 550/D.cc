#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a[200005], b[200005]{};
	cin >> n;
	for(int i =1; i<=n; ++i) {
		cin >> a[i];
		b[a[i]]++;
	}
	int mx = 0, mxo;
	for(int i =0; i<200005; ++i) if (mx < b[i]) mx = b[i], mxo = i;
	queue<int> q;
	vector<tuple<int, int, int>> ans;
	for(int i =1; i<=n; ++i) {
		if (a[i] == mxo) q.push(i);
	}
	a[0] = a[n + 1] = mxo;
	while(q.size()) {
		int c = q.front(); q.pop();
		if (a[c - 1] != mxo) {
			ans.push_back({a[c - 1] < a[c] ? 1 : 2, c - 1, c});
			a[c - 1] = mxo;
			q.push(c - 1);
		}
		if (a[c + 1] != mxo) {
			ans.push_back({a[c + 1] < a[c] ? 1 : 2, c + 1, c});
			a[c + 1] = mxo;
			q.push(c + 1);
		}
	}
	cout << ans.size() << '\n';
	for(auto& [o, i, j] : ans) cout << o << ' ' << i << ' ' << j << '\n';
}