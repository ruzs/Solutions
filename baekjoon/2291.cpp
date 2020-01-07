#include <bits/stdc++.h>
using namespace std;

int n, m, k;
long long d[221][11][221];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i =1; i<=m; ++i) d[i][1][i] = 1;
	for(int i =2; i<=n; ++i) {
		for(int j =1; j<=m; ++j) {
			for(int f =1; f<=j; ++f) {
				for(int s =f; s<=j; ++s) {
					if (j-f >= 1)
					d[f][i][j] += d[s][i - 1][j - f];
				}
			}
		}
	}
	int i =1;
	while(n) {
		for(; i<=m; ++i) {
			auto a = d[i][n][m];
			if (a < k) k -= a;
			else {
				printf("%d ", i);
				m -= i;
				n -= 1;
				break;
			}
		}
	}
}
