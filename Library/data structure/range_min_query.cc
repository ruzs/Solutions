struct rmq {
	#define N 1<<20
	int a[N<<1];
	void init(int * b, int n) {
		for(int i =0; i<N; ++i) a[i + N] = i<n ? b[i] : 1e9;
		for(int i =N-1; i; --i) a[i] = min(a[i<<1], a[i<<1|1]);
	}
	void update(int p, int x) {
		a[p += N] = x;
		while(p >>= 1) a[p] = min(a[p<<1], a[p<<1|1]);
	}
	auto query(int s, int e) {
		int r = min(a[s += N], a[e += N]);
		while(s <= e) {
			if (s % 2 == 1) r = min(r, a[s++]);
			if (e % 2 == 0) r = min(r, a[e--]);
			s >>= 1; e >>= 1;
		}
		return r;
	}
};