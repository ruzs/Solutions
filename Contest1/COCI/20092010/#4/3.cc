#include <bits/stdc++.h>

using namespace std;

auto getFactors(int x) {
	map<int, int> r;
	for(int i =2; i*i<=x; ++i) {
		int cnt = 0;
		while (x % i == 0) x /= i, cnt++;
		r[i] = cnt;
	}
	if (x) r[x]++;
	return r;
}
int main() {
	int n, a;
	map<int, int> f[101], ans;
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> a;
		f[i] = getFactors(a);
		for(auto& j : f[i]) ans[j.first] += j.second;
	}
	long long gcd = 1;
	for(auto & i : ans) gcd *= pow(i.first, i.second /= n);
	int cnt = 0;
	for(int i =0; i<n; ++i) {
		for(auto &j : ans) {
			if (j.second > f[i][j.first]) cnt += j.second - f[i][j.first];
		}
	}
	cout << gcd << '\n' << cnt;
}