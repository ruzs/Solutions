#include <cstdio>

struct Trie {
	int a[1000005][26], x[1000005], n =0;
	void insert(char * s) {
		int i =0;
		while(*s) {
			int & nxt = a[i][*s++ - 'a'];
			i = nxt ? nxt : nxt = ++n;
			x[i]++;
		}
	}
	int query(int &i, char c) {
		i = a[i][c - 'a'];
		return x[i];
	}
} trie;

const int mod = 1e9 + 7;

int d[200005];
int dp(int i, char * s) {
	if (!*s) return 1;

	int & ref = d[i];
	if (ref != -1) return ref;

	ref = 0;
	int j = 0;
	while(*s) {
		int x = trie.query(j, *s++);
		if (x) ref = (1LL * x * dp(++i, s) + ref) % mod;
		else break;
	}
	return ref;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i =0; i<n; ++i) {
		char s[305];
		scanf(" %s", s);
		trie.insert(s);
	}
	char word[200005];
	scanf(" %s", word);

	for(int i =0; i<200005; ++i) d[i] = -1;
	printf("%d", dp(0, word));
}
