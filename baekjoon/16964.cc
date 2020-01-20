#include <bits/stdc++.h>

using namespace std;

int n;
set<int> g[100001];
vector<int> d, order;
void dfs(int a, vector<int>::iterator& it) {
	d[a] = 1;
	while (it != order.end() && g[a].count(*it)) {
		int b = *it++;
		if (!d[b]) dfs(b, it);
	}
}
int main() {
	cin >> n;
	d.resize(n + 1);
	for(int i =1; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].insert(b);
		g[b].insert(a);
	}
	order.resize(n);
	for(int &i : order) cin >> i;
	auto it = order.begin();
	
	if (*it != 1) return cout << 0, 0;
	
	++it;
	dfs(1, it);

	cout << (it == order.end());
}