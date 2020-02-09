struct LCA {
	#define N 17
	int p[1<<N][N], h[1<<N];
	vector<int> * g;
	void init(vector<int> *_g, int _r) {
		g = _g;
		h[_r] = 1;
		preproc(_r);
	}
	void preproc(int a) {
		for(int b : g[a]) if (b != p[a][0]) {
			h[b] = h[a] + 1;
			p[b][0] = a;
			for(int j =1; j<N; ++j)
				p[b][j] = p[p[b][j - 1]][j - 1];
			preproc(b);
		}
	}
	int find(int a, int b) {
		if (h[a] > h[b]) swap(a, b);
		for(int j =N-1; ~j; --j)
			if (h[a] <= h[p[b][j]]) b = p[b][j];
		if (a == b) return a;
		for(int j =N-1; ~j; --j)
			if (p[a][j] != p[b][j]) {
				a = p[a][j];
				b = p[b][j];
			}
		return p[a][0];
	}
} lca;