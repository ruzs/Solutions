#define N 100005
struct rmq {
	int a[N << 2], n;
	void init(int _n, int* _a) {
		n = _n - 1;
		for(int i =1; i<=16; i<<=1) n |= n >> i;
		n++;
		for(int i =0; i<n; ++i) a[i + n] = i<_n ? _a[i] : 1e9;
		for(int i =n-1; i; --i) a[i] = min(a[i<<1], a[i<<1|1]);
	}
	void update(int p, int x) {
		a[p += n] = x;
		while(p >>= 1) a[p] = min(a[p<<1], a[p<<1|1]);
	}
	int query(int s, int e) {
		int r = 1e9;
		s += n; e += n;
		while(s <= e) {
			if (s % 2 == 1) r = min(r, a[s++]);
			if (e % 2 == 0) r = min(r, a[e--]);
			s >>= 1; e >>= 1;
		}
		return r;
	}
};