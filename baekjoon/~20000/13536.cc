#include <bits/stdc++.h>

using namespace std;

struct T {
	int s, l, r;
} st[1 << 21];
int L, R;
T unite(T a, T b) {
	T ret;
	int d = min(a.r, b.l);
	ret.s = a.s + b.s + 2 * d;
	ret.l = a.l + (a.r == d ? b.l - d : 0);
	ret.r = b.r + (b.l == d ? a.r - d : 0);
	return ret;
}
void update(int p, T x, int i = 1, int l = L, int r = R) {
	if (l == r) st[i] = x;
	else {
		int m = l + r >> 1;
		if (p <= m) update(p, x, i << 1, l, m);
		else update(p, x, i << 1 | 1, m + 1, r);
		st[i] = unite(st[i << 1], st[i << 1 | 1]);
	}
}
T query(int s, int e, int i = 1, int l = L, int r = R) {
	if (e < l || r < s) return {0, 0, 0};
	if (s <= l && r <= e) return st[i];
	int m = l + r >> 1;
	return unite(query(s, e, i << 1, l, m), query(s, e, i << 1 | 1, m + 1, r));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	L = 0, R = s.size() - 1;
	for(int i =0; i<s.size(); ++i)
		if (s[i] == '(') update(i, {0, 0, 1});
		else update(i, {0, 1, 0});
	int n;
	cin >> n;
	while(n--) {
		int s, e;
		cin >> s >> e;
		cout << query(s - 1, e - 1).s << '\n';
	}
}