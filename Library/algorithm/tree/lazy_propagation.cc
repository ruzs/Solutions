#define N 100005

#define LEFT n<<1,l,(l+r)>>1
#define RIGHT (n<<1)+1,((l+r)>>1)+1,r

int tree[N << 2], lazy[N << 2];

void propagate(int n, int l, int r) {
	if (lazy[n]) {
		tree[n] += lazy[n] * (r - l + 1);
		if (l != r) {
			lazy[n << 1] += lazy[n];
			lazy[n<<1|1] += lazy[n];
		}
		lazy[n] = 0;
	}
}
void update(int n, int l, int r, int p, int x) {
	if (p < l || r < p) return;
	propagate(n, l, r);
	if (l == r) tree[n] = x;
	else {
		update(LEFT, p, x);
		update(RIGHT, p, x);
		tree[n] = tree[n<<1] + tree[n<<1|1];
	}
}
int query(int n, int l, int r, int s, int e) {
	if (e < l || r < s) return 0;
	propagate(n, l, r);
	if (s <= l && r <= e) return tree[n];
	return query(LEFT, s, e) + query(RIGHT, s, e);
}