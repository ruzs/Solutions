#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	bool a[100005], b[100005], c[100005];
	scanf("%d", &n);
	for(int i =0; i<n; ++i) scanf("%1d", &a[i]), c[i] = a[i];
	for(int i =0; i<n; ++i) scanf("%1d", &b[i]);

	int cnt =0;
	for(int i =0; i + 1<n; ++i) {
		if (a[i] != b[i]) {
			cnt++;
			a[i] ^= 1;
			a[i + 1] ^= 1;
			a[i + 2] ^= 1;
		}
	}
	if (a[n - 1] != b[n - 1]) {
		cnt = 1;
		c[0] ^= 1;
		c[1] ^= 1;
		for(int i =0; i + 1<n; ++i) {
			if (c[i] != b[i]) {
				cnt++;
				c[i] ^= 1;
				c[i + 1] ^= 1;
				c[i + 2] ^= 1;
			}
		}
		if (c[n - 1] != b[n - 1]) return puts("-1"), 0;
	}
	printf("%d", cnt);
}