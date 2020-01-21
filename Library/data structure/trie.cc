#define N 1000 	//최대개수
#define L 20	//최대길이
#define A 26	//알파벳사이즈
struct Trie {
	int a[N * L + 1][A], x[N * L + 1], n = 0;
	void init() {
		memset(a, 0, sizeof a);
		memset(x, 0, sizeof x);
		n = 0;
	}
	int find(char* s, bool i) {
		int p = 0;
		while(*s) {
			int& np = a[p][*s - 'a'];
			if (!np) { if (!i) return 0; np = ++n; }
			p = np;
		}
		return p;
	}
	void insert(char* s) {
		x[find(s, 1)]++;
	}
	int count(char* s) {
		return x[find(s, 0)];
	}
};