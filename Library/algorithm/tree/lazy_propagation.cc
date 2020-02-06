#define N 1 << 17

#define LEFT n<<1,l,l+r>>1
#define RIGHT n<<1|1,(l+r>>1)+1,r

long long tree[N << 1], lazy[N << 1];

inline void propagate(int n, int l, int r) {
	tree[n] += lazy[n] * (r - l + 1);
	if (l != r) {
		lazy[n << 1] += lazy[n];
		lazy[n<<1|1] += lazy[n];
	}
	lazy[n] = 0;
}
void update(int n, int l, int r, int s, int e, int x) {
	if (lazy[n]) propagate(n, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		lazy[n] += x;
		propagate(n, l, r);
		return;
	}
	update(LEFT, s, e, x);
	update(RIGHT, s, e, x);
	tree[n] = tree[n<<1] + tree[n<<1|1];
}
int query(int n, int l, int r, int s, int e) {
	if (e < l || r < s) return 0;
	if (lazy[n]) propagate(n, l, r);
	if (s <= l && r <= e) return tree[n];
	return query(LEFT, s, e) + query(RIGHT, s, e);
}