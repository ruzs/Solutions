#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
const int mod = 1e9 + 7;

ii st[1 << 20];
ii unite(ii a, ii b) {
	if (a.first == b.first) return {a.first, (a.second + b.second) % mod};
	return a > b ? a : b;
}

void update(int p, ii x, int i =1, int l =0, int r =1 << 19) {
	if (l == r) st[i] = unite(st[i], x);
	else {
		int m = l + r >> 1;
		if (p <= m) update(p, x, i << 1, l, m);
		else update(p, x, i << 1 | 1, m + 1, r);
		st[i] = unite(st[i << 1], st[i << 1 | 1]);
	}
}
ii query(int s, int e, int i =1, int l =0, int r =1 << 19) {
	if (e < l || r < s) return {0, 0};
	if (s <= l && r <= e) return st[i];
	int m = l + r >> 1;
	return unite(query(s, e, i << 1, l, m), query(s, e, i << 1 | 1, m + 1, r));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ii> a(n);
	vector<int> ord;
	for(ii & i : a) {
		cin >> i.first >> i.second;
		ord.push_back(i.second);
	}
	sort(ord.begin(), ord.end());
	ord.erase(unique(ord.begin(), ord.end()), ord.end());
	sort(a.begin(), a.end(), [](ii a, ii b) {
		return a.first < b.first || a.first == b.first && a.second > b.second;
	});
	update(0, {0, 1});
	for(ii & i : a) {
		int x = lower_bound(ord.begin(), ord.end(), i.second) - ord.begin() + 1;
		ii r = query(0, x - 1);
		r.first++;
		update(x, r);
	}
	ii r = query(0, 1 << 19);
	cout << r.first << ' ' << r.second;
}