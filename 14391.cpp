#include <bits/stdc++.h>
using namespace std;

int n, m, a[4][4], ans;
int d[1 << 16];

int enc(int i, int j) { return i * m + j; }

int rec(int s) {
	if (s + 1 == 1 << (n * m)) return 0;

	int & ref = d[s];
	if (ref != -1) return ref;

	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			if (s & (1 << enc(i, j))) continue;
			int ps = 0, ns = s;
			for(int k =0; i+k<n; ++k) {
				if (ns & (1 << enc(i + k, j))) break;
				ns |= 1 << enc(i + k, j);
				ps = ps * 10 + a[i + k][j];
				ref = max(ref, ps + rec(ns));
			}
			ps = 0; ns = s;
			for(int k =0; j+k<m; ++k) {
				if (ns & (1 << enc(i, j + k))) break;
				ns |= 1 << enc(i, j + k);
				ps = ps * 10 + a[i][j + k];
				ref = max(ref, ps + rec(ns));
			}
		}
	}
	return ref;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			scanf("%1d", &a[i][j]);
		}
	}
	memset(d, -1, sizeof d);
	printf("%d", rec(0));
}
