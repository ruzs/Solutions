#include <iostream>
using namespace std;

int strcmp(char * a, char * b) {
	int i =0;
	while(a[i] && a[i] == b[i]) i++;
	return a[i] - b[i];
}
void strcpy(char *dst, char *src) {
	int i =0;
	while(src[i]) dst[i] = src[i], i++;
	dst[i] = 0;
}

const int N = 1e5 + 5;

class dsu {
	int p[N];
public:
	dsu() { for(int i =0; i<N; ++i) p[i] = -1; }
	int find(int u) {
		return p[u] < 0 ? u : p[u] = find(p[u]);
	}
	int merge(int u, int v) {
		u = find(u); v = find(v);
		if (u != v) { p[u] += p[v]; p[v] = u; }
		return -p[u];
	}
};

class Hash {
	struct {
		char key[21];
		int data;
	} tb[N << 1];
	int n;
	int enc(char * key) {
		int h =5381;
		while(*key) h = ((h << 7) - h + *key++) % N;
		return h;
	}
public:
	Hash() : n(0) { for(int i =0; i<N<<1; ++i) tb[i].key[0] = 0; }
	int& operator[](char * key) {
		int h = enc(key);
		while(tb[h].key[0]) {
			if (strcmp(tb[h].key, key) == 0) return tb[h].data;
			h = (h + 1) % N;
		}
		strcpy(tb[h].key, key);
		return tb[h].data = ++n;
	}
};

void solve() {
	dsu ds;
	Hash hs;
	char s[21], t[21];
	int n; cin >> n;

	while(n--) {
		cin >> s >> t;
		cout << ds.merge(hs[s], hs[t]) << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
}
