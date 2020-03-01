#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n;
double d[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =1; i<=n; ++i) {
		double s = 0;
		for(int j =1; j<=6; ++j) {
			if (i < j) break;
			s += d[i - j];
		}
		d[i] = 1 + s / 6;
	}
	cout << setprecision(20) << d[n];
}
