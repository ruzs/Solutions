#include <bits/stdc++.h>
using namespace std;

int enc(char c) {
	return islower(c) ? c - 'a' : c - 'A' + 26;
}
struct Trie {
	int a[5011][52]{}, x[5011]{}, n = 0;
	void insert(string & s, int idx) {
		int i = 0;
		for(char c : s) {
			if (!a[i][enc(c)]) a[i][enc(c)] = ++n;
			i = a[i][enc(c)];
		}
		x[i] = idx;
	}
	int find(string & s) {
		int i = 0;
		for(char c : s) {
			if (!a[i][enc(c)]) return -1;
			i = a[i][enc(c)];
		}
		return x[i];
	}
} tr;
int n, m, l, a[101], choic[101][501];
string s[501];
double T[501][501], M[501][501], d[101][501];
bool c[101][501];
double dp(int i, int p) {
	if (i > l) return 0.0;

	if (c[i][p]) return d[i][p];
	c[i][p] = 1;

	double res = -1e200;
	for(int j =1; j<=n; ++j) {
		double x = T[p][j] + M[j][a[i]] + dp(i + 1, j);
		if (res < x) {
			res = x;
			choic[i][p] = j;
		}
	}
	return d[i][p] = res;
}
void backtrack() {
	memset(c, 0, sizeof c);
	dp(1, 0);
	for(int i =1, p =0; i<=l; ++i)
		cout << s[p = choic[i][p]] << ' ';
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i =1; i<=n; ++i) {
		cin >> s[i];
		tr.insert(s[i], i);
	}
	for(int i =0; i<=n; ++i) {
		for(int j =1; j<=n; ++j) {
			cin >> T[i][j];
			T[i][j] = log(T[i][j]);
		}
	}
	for(int i =1; i<=n; ++i) {
		for(int j =1; j<=n; ++j) {
			cin >> M[i][j];
			M[i][j] = log(M[i][j]);
		}
	}
	while(m--) {
		cin >> l;
		for(int i =1; i<=l; ++i) {
			cin >> s[0];
			a[i] = tr.find(s[0]);
		}
		backtrack();
	}
}
