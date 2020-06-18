#include <bits/stdc++.h>

using namespace std;

int st[1 << 20], lz[1 << 20], S, E;
void push(int i, int l, int r) {
	if (lz[i]) {
		st[i] = lz[i];
		if (l != r) {
			lz[i << 1] = lz[i];
			lz[i << 1 | 1] = lz[i];
		}
		lz[i] = 0;
	}
}
void update(int s, int e, int x, int i =1, int l =S, int r =E) {
	push(i, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		lz[i] = x;
		push(i, l, r);
	} else {
		int m = l + r >> 1;
		update(s, e, x, i << 1, l, m);
		update(s, e, x, i << 1 | 1, m + 1, r);
		st[i] = st[i << 1] | st[i << 1 | 1];
	}
}
int query(int s, int e, int i = 1, int l = S, int r = E) {
	push(i, l, r);
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return st[i];
	int m = l + r >> 1;
	return query(s, e, i << 1, l, m) | query(s, e, i << 1 | 1, m + 1, r);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t, q;
	cin >> n >> t >> q;
	S = 1, E = n;
	update(1, n, 1 << 1);
	while(q--) {
		char cmd;
		int x, y, z;
		cin >> cmd >> x >> y;
		if (x > y) swap(x, y);
		if (cmd == 'C') {
			cin >> z;
			update(x, y, 1 << z);
		} else {
			cout << __builtin_popcount(query(x, y)) << '\n';
		}
	}
}