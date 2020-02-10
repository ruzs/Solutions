#include <bits/stdc++.h>

using namespace std;

#define N 1 << 20

#define LEFT n<<1,l,l+r>>1
#define RIGHT n<<1|1,(l+r>>1)+1,r

double tree[N << 1], lazy[N << 1];

inline void propagate(int n, int l, int r) {
	tree[n] = lazy[n] * (r - l + 1);
	if (l != r) {
		lazy[n << 1] = lazy[n];
		lazy[n<<1|1] = lazy[n];
	}
	lazy[n] = 0;
}
void update(int n, int l, int r, int s, int e, double x) {
	if (lazy[n]) propagate(n, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		lazy[n] = x;
		propagate(n, l, r);
		return;
	}
	update(LEFT, s, e, x);
	update(RIGHT, s, e, x);
	tree[n] = tree[n<<1] + tree[n<<1|1];
}
double query(int n, int l, int r, int s, int e) {
	if (e < l || r < s) return 0;
	if (lazy[n]) propagate(n, l, r);
	if (s <= l && r <= e) return tree[n];
	return query(LEFT, s, e) + query(RIGHT, s, e);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	double x;
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> x;
		update(1, 0, n - 1, i, i, x);
	}
	update(1, 0, n - 1, n, n, 1e9);
	int s = 0, e = 0;
	for(int i =0; i<n; ++i) {
		if (query(1, 0, n - 1, i, i) < query(1, 0, n - 1, i + 1, i + 1)) {
			update(1, 0, n - 1, s, e, x = query(1, 0, n - 1, s, e) / (e - s + 1));
			s = e = i + 1;
		}
		else {
			e++;
		}
	}
	update(1, 0, n - 1, s, e - 1, query(1, 0, n - 1, s, e - 1) / (e - s));
	for(int i =0; i<n; ++i) {
		cout << setprecision(20) << query(1, 0, n - 1, i, i) << '\n';
	}
}