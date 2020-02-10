#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[4], b = 0, m = -1;
	scanf("%u", &n);
	scanf("%u.%u.%u.%u", &a[3], &a[2], &a[1], &a[0]);
	for(int i =3; ~i; --i) b |= a[i] << (i << 3);
	while(--n) {
		scanf("%u.%u.%u.%u", &a[3], &a[2], &a[1], &a[0]);
		for(int i =3; ~i; --i) {
			for(int j =7; ~j; --j) {
				if (!(b & 1 << (i << 3) + j) ^ !(a[i] & 1 << j)) {
					m = max<int>(m, (i << 3) + j);
				}
			}
		}
	}
	b &= ~((1LL << m + 1) - 1);
	printf("%u.%u.%u.%u\n", b >> 24 & 255, b >> 16 & 255, b >> 8 & 255, b & 255);
	b = ~((1LL << m + 1) - 1);
	printf("%u.%u.%u.%u\n", b >> 24 & 255, b >> 16 & 255, b >> 8 & 255, b & 255);
}