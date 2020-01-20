#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	set<int> g[100001];

	cin >> n;
	vector<int> d(n + 1), order(n);
	for(int i =1; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].insert(b);
		g[b].insert(a);
	}
	for(int &i : order) cin >> i;
	auto it = order.begin();

	queue<int> q;
	if (*it == 1) it++;
	q.push(1);
	d[1] = 1;

	while(q.size()) {
		int a = q.front(); q.pop();
		while(it != order.end() && g[a].count(*it)) {
			if (!d[*it]) {
				d[*it] = 1;
				q.push(*it);
				it++;
			}
			else break;
		}
	}
	cout << (it == order.end());
}