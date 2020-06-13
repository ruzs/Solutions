#include <bits/stdc++.h>

using namespace std;

int st[1 << 21], lz[1 << 21], N;

void push(int i, int l, int r) {
	if (~lz[i]) {
		st[i] = lz[i] < 0 ? (r - l + 1) - st[i] : lz[i] * (r - l + 1);
		if (l != r) for(int j : {i << 1, i << 1 | 1})
			if (lz[i] < 0) lz[j] ^= 1;
			else lz[j] = lz[i];
		lz[i] = -1;
	}
}
void update(int s, int e, int x, int i = 1, int l = 0, int r = N) {
	push(i, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		if (x < 0) lz[i] ^= 1;
		else lz[i] = x;
		push(i, l, r);
	} else {
		int m = l + r >> 1;
		update(s, e, x, i << 1, l, m);
		update(s, e, x, i << 1 | 1, m + 1, r);
		st[i] = st[i << 1] + st[i << 1 | 1];
	}
}
int query(int i = 1, int l = 0, int r = N) {
	push(i, l, r);
	if (l == r) return l;
	int m = l + r >> 1;
	push(i << 1, l, m);
	push(i << 1 | 1, m + 1, r);
	if (st[i << 1] < m - l + 1) return query(i << 1, l, m);
	else return query(i << 1 | 1, m + 1, r);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<tuple<int, long long, long long>> a;
	vector<long long> X = {1};
	for(int i =0; i<n; ++i) {
		long long cmd, l, r;
		cin >> cmd >> l >> r;
		a.emplace_back(cmd, l, r);
		for(int j =-1; j<=1; ++j) {
			if (l + j > 0) X.push_back(l + j);
			if (r + j > 0) X.push_back(r + j);
		}
	}
	sort(X.begin(), X.end());
	X.resize(unique(X.begin(), X.end()) - X.begin());
	N = X.size();
	memset(lz, -1, sizeof lz);

	for(auto & [cmd, l, r] : a) {
		l = lower_bound(X.begin(), X.end(), l) - X.begin();
		r = lower_bound(X.begin(), X.end(), r) - X.begin();
		if (cmd == 1) update(l, r, 1);
		if (cmd == 2) update(l, r, 0);
		if (cmd == 3) update(l, r, -2);
		cout << X[query()] << '\n';
	}
}