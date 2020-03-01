#include <bits/stdc++.h>

using namespace std;

auto fio = ios::sync_with_stdio(0);

int n, m, d[200005];
pair<int, int> a[200005];
map<int, vector<int>> be, el;
queue<int> q;

int main() {
	memset(d, -1, sizeof d);
	cin >> n >> m;
	for(int i =0; i<n; ++i) {
		cin >> a[i].first >> a[i].second;
		if (!a[i].second) {
			d[i] = 1;
			q.push(i);
		}
		else be[a[i].second].push_back(i);
	}
	for(int i =0; i<n; ++i) {
		cin >> a[i+n].second >> a[i+n].first;
		if (!a[i+n].second) {
			d[i+n] = 1;
			q.push(i+n);
		}
		else el[a[i+n].second].push_back(i+n);
	}
	while(q.size()) {
		int here = q.front(); q.pop();
		auto& mp = (here < n ? el : be);
		auto lb = mp.lower_bound(a[here].first - m);
		auto ub = mp.upper_bound(a[here].first);
		while(lb != ub) {
			for(int next : lb->second) {
				d[next] = d[here] + 1;
				q.push(next);
			}
			lb = mp.erase(lb);
		}
	}
	for(int i =0; i<n; ++i) cout << d[i] << ' ';
}