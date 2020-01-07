#include <bits/stdc++.h>
using namespace std;

int n, a[3001], d[3001], b, c;
int main() {
	scanf("%d", &n);
	for(int i =1; i<=n; ++i) scanf("%d", a + i);
	scanf("%d %d", &b, &c);
	sort(a + 1, a + n + 1);
	for(int i =1; i<=n; ++i) {
		d[i] = d[i - 1] + a[i] * b;
		for(int j =i, k =c; j; --j) {
			k += (a[(j + i + 1) / 2] - a[j]) * b;
			d[i] = min(d[i], d[j - 1] + k);
		}
	}
	cout << d[n];
}
