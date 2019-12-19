#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n, a[100], b[100], d[100][10][10];

int c[] = {0,1,1,1,2,2,2,1,1,1};
int dp(int i, int j, int k) {
	if (i == n) return 0;

	int & ref = d[i][j][k];
	if (ref != -1) return ref;
    
	ref = 1e9;
	for(int s =0; s<10; ++s) {
		for(int t =0; t<10; ++t) {
			int r = (b[i] - (a[i] + j + s + t) % 10 + 10) % 10;
			ref = min(ref, c[r] + c[s] + c[t] + dp(i + 1, (k + s + t) % 10, t));
		}
	}
	return ref;
}
int main() {
	memset(d, -1, sizeof d);
	scanf("%d", &n);
	for(int i =0; i<n; ++i) scanf("%1d", a + i);
	for(int i =0; i<n; ++i) scanf("%1d", b + i);
	printf("%d", dp(0, 0, 0));
}
