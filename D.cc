#include <bits/stdc++.h>
<<<<<<< HEAD
 
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
=======

using namespace std;

char c[200001];
int k, n[200001];
void solve() {
	scanf("%d %s", &k, c);
	memset(n, -1, sizeof n);
	n[k] = -1;
	c[k] = '>';
	for (int i = k; i >= 0; --i)
		for (int j = 0; j <= k; ++j) {
			if (c[j] == '<' || n[j] != -1) continue;
			if (c[j] == '>') {
				n[j--] = i--;
				while (j >= 0 && c[j] == '<') n[j--] = i--;
			}
		}
	for (int i = 0; i <= k; ++i)
		printf("%d", n[i]), n[i] = -1;
	puts("");
	c[k] = '<';
	for (int i = 0; i < k; ++i)
		for (int j = 0; j <= k; ++j) {
			if (c[j] == '>' || n[j] != -1) continue;
			if (c[j] == '<') {
				n[j--] = i++;
				while (j >= 0 && c[j] == '>') n[j--] = i++;
			}
		}
	for (int i = 0; i <= k; ++i)
		printf("%d", n[i]);
}
int main() {
	int T, t =0; cin >> T;
	while(++t <= T) solve();
>>>>>>> ef72632469cae9f198d75202044b6e0cfa8dcd9e
}