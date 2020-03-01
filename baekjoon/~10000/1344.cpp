#include <bits/stdc++.h>
using namespace std;

bool isPrime[20] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0};
double A, B, d[20][20][20], ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;
	A /= 100;
	B /= 100;
	d[0][0][0] = 1.0;
	for(int i =1; i<=18; ++i) {
		for(int j =0; j<=i; ++j) {
			for(int k =0; k<=i; ++k) {
				if (j && k)
					d[i][j][k] += d[i - 1][j - 1][k - 1] * A * B;
				if (k)
					d[i][j][k] += d[i - 1][j][k - 1] * (1.0 - A) * B;
				if (j)
					d[i][j][k] += d[i - 1][j - 1][k] * A * (1.0 - B);
				d[i][j][k] += d[i - 1][j][k] * (1.0 - A) * (1.0 - B);
			}
		}
	}
	for(int i =0; i<=18; ++i) {
		for(int j =0; j<=18; ++j) {
			if (isPrime[i] || isPrime[j]) ans += d[18][i][j];
		}
	}
	cout << setprecision(20) << ans;
}
