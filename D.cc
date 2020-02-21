#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, k, a, b, c[200005], d[200005];
vector<int> g[200005], v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> m >> k;
	for(int i =0; i<k; ++i) cin >> c[i];
	for(int i =0; i<m; ++i) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	//bfs
	memset(d, -1, sizeof d);
	queue<int> q;
	q.push(1);
	d[1] = 0;
	while(q.size()) {
		int a = q.front(); q.pop();
		for(int b : g[a]) {
			if (~d[b]) continue;
			d[b] = d[a] + 1;
			q.push(b);
		}
	}
	for(int i =0; i<k; ++i) v.push_back(c[i]);
	sort(v.begin(), v.end(), [&](int a, int b) {
		return d[a] < d[b];
	});
	int mn = 1e9;
	for(int i =1; i<v.size(); ++i) {
		int diff = d[v[i]] - d[v[i-1]] - 1;
		if (mn > diff) {
			mn = diff;
			a = v[i];
			b = v[i - 1];
		}
	}
	g[a].push_back(b);
	g[b].push_back(a);
	memset(d, -1, sizeof d);
	q.push(1);
	d[1] = 0;
	while(q.size()) {
		int a = q.front(); q.pop();
		for(int b : g[a]) {
			if (~d[b]) continue;
			d[b] = d[a] + 1;
			q.push(b);
		}
	}
	cout << d[n];
}