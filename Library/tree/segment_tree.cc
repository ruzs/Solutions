#define N 1<<20
struct segment_tree {
	int a[N<<1];
	void init(int * b, int n) {
		for(int i =0; i<N; ++i) a[i + N] = b[i];
		for(int i =N-1; i; --i) a[i] = a[i<<1] + a[i<<1|1];
	}
	void update(int p, int x) {
		a[p += N] = x;
		while(p >>= 1) a[p] = a[p<<1] + a[p<<1|1];
	}
	auto query(int s, int e) {
		int r = 0;
		while(s <= e) {
			if (s % 2 == 1) r += a[s++];
			if (e % 2 == 0) r += a[e--];
			s >>= 1; e >>= 1;
		}
		return r;
	}
} seg;