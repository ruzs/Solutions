#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;

int n, a, b, c[N], d[N];
vector<int> g[N];
int dfs(int a) {
	int & ref = d[a];
	if (ref != -1) return ref;
	ref = 0;
	for(int i : g[a]) {
		ref = max(ref, dfs(i));
	}
	return ref += c[a];
}
int dfsall() {
	int r = 0;
	for(int i =1; i<=n; ++i) {
		r = max(r, dfs(i));
	}
	return r;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(d, -1, sizeof d);
	cin >> n;
	for(int i =1; i<=n; ++i) {
		cin >> c[i] >> a;
		while(a--) {
			cin >> b;
			g[i].push_back(b);
		}
	}
	cout << dfsall();
}
