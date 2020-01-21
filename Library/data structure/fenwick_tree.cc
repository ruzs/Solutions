#define N 100005
struct fwt {
	int a[N];
	void init() {
		memset(a, 0, sizeof a);
	}
	void add(int p, int dif) {
		while(p < N) a[p] += dif, p += p & -p;
	}
	int sum(int p) {
		int r = a[p];
		while(p -= p & -p) r += a[p];
		return r;
	}
};