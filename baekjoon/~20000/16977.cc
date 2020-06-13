#include <bits/stdc++.h>

using namespace std;

struct E {
	int s = 1, l = 0, r = 0, opt = 0;
};
E unite(E a, E b) {
	E ret;
	ret.s = a.s + b.s;
	ret.l = a.l == a.s ? a.s + b.l : a.l;
	ret.r = b.r == b.s ? b.s + a.r : b.r;
	ret.opt = max({a.opt, b.opt, a.r + b.l});
	return ret;
}
struct node {
	E v;
	node * l = 0, * r = 0;
	node() {}
	node(int x) : v({x, x, x, x}) {}
	node(node * l, node * r) : l(l), r(r) {
		if (l && r) v = unite(l->v, r->v);
	}
};
int N;
vector<node *> st;

node * build(int l = 1, int r = N) {
	if (l == r) return new node();
	int m = l + r >> 1;
	return new node(build(l, m), build(m + 1, r));
}
node * add(node * v, int p, int l = 1, int r = N) {
	if (l == r) return new node(1);
	else {
		int m = l + r >> 1;
		if (p <= m) return new node(add(v->l, p, l, m), v->r);
		else return new node(v->l, add(v->r, p, m + 1, r));
	}
}
E query(node * v, int s, int e, int l = 1, int r = N) {
	if (e < l || r < s) return {0, 0, 0, 0};
	if (s <= l && r <= e) return v->v;
	int m = l + r >> 1;
	return unite(query(v->l, s, e, l, m), query(v->r, s, e, m + 1, r));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n + 1);
	for(int i =1; i<=n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.rbegin(), a.rend() - 1);
	N = n;
	st.push_back(build());
	for(int i =1; i<=n; ++i) {
		st.push_back(add(st.back(), a[i].second));
	}
	int q;
	cin >> q;
	for(int i =0; i<q; ++i) {
		int l, r, w;
		cin >> l >> r >> w;
		int s = 1, e = n;
		while(s != e) {
			int m = s + e >> 1;
			E x = query(st[m], l, r);
			if (x.opt >= w) e = m;
			else s = m + 1;
		}
		cout << a[s].first << '\n';
	}
}