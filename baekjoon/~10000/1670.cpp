#include <bits/stdc++.h>
using namespace std;

long long n, d[10001], m = 987654321;

int main() {
	cin >> n;
	d[0] = 1;
	for(int i =2, j; i<=n; i+=2) {
		for(j =1; j+j<i; j+=2) {
			d[i] += (d[i - j - 1] * d[j - 1]) % m;
			d[i] %= m;
		}
		d[i] *= 2;
		if (j * 2 == i)	d[i] += (d[i / 2 - 1] * d[i / 2 - 1]) % m;
		d[i] %= m;
	}
	cout << d[n] % m;
}
