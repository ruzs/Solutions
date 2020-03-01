#include <bits/stdc++.h>

using namespace std;

long long n;
int m, k;
double ans;
map<long long, double> d[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	d[0][n] = 1.0;
	for(int i =1; i<=k; ++i) {
		for(auto & j : d[i - 1]) {
			d[i][j.first - j.first / m] += j.second * (m - j.first % m) / m;
			d[i][j.first - j.first / m - 1] += j.second * (j.first % m) / m;
		}
	}
	for(auto & i : d[k]) {
		if (i.first) ans += i.second;
	}
	cout << setprecision(20) << ans;
}
