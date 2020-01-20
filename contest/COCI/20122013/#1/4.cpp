#include<cstdio>

int n, m, a[300001], lo, hi = 1e9, md, sum;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%d", &a[i]);
	while (lo < hi) {
		md = (lo + hi) >> 1;
		sum = 0;
		for (int i = 0; i < m; ++i) {
			sum += (a[i] + md - 1) / md;
		}
		if (sum > n) lo = md + 1;
		else hi = md;
	}
	printf("%d", lo);
}
