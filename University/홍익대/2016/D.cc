#include <cstdio>

int n, b[1 << 20];
int main() {
	while(scanf("%d", &n) != EOF) {
		if (b[n / 32] & 1 << n % 32) continue;
		printf("%d ", n);
		b[n / 32] |= 1 << n % 32;
	}
}