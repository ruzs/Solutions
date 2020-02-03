struct fwt {
	#define N 100005
	int a[N];
	void add(int p, int x) {
		while(p < N) a[p] += x, p += p & -p;
	}
	auto sum(int p) {
		int r = a[p];
		while(p -= p & -p) r += a[p];
		return r;
	}
} fw;