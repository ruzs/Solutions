#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for(int i =2; i<=n; ++i) {
		int p;
		cin >> p;
		g[p].push_back(i);
	}
	vector<int> score(n + 1);
	for(int i =1; i<=n; ++i) cin >> score[i];
	vector<int> d(n + 1, -1);
	function<int(int)> dp = [&](int a) {
		int & ref = d[a];
		if (~ref) return ref;
		//nonmatching
		int nomat = 0;
		for(int b : g[a]) {
			nomat += dp(b);
		}
		ref = nomat;
		//matching
		for(int b : g[a]) {
			int sum = score[a] * score[b];
			for(int c : g[b]) {
				sum += dp(c);
			}
			ref = max(ref, nomat - dp(b) + sum);
		}
		return ref;
	};
	cout << dp(1);
}