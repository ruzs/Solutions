#include<cstdio>

int n, in, post[100001], idx[100001];

void pre(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) return;
	printf("%d ", post[pe]);
	pre(is, idx[post[pe]] - 1, ps, pe - ie + idx[post[pe]] - 1);
	pre(idx[post[pe]] + 1, ie, pe - ie + idx[post[pe]], pe - 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &in), idx[in] = i;
	for (int i = 1; i <= n; ++i) scanf("%d", &post[i]);
	pre(1, n, 1, n);
}