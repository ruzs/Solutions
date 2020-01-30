#include <bits/stdc++.h>

using namespace std;

const int N = 1e7+5;

bool np[N>>1];

inline auto primeList(int max_n) {
	vector<long long> r = {2};
	long long i =1, j, k;
	while((i+=2) <= max_n) {
		if (np[i>>1]) continue;
		r.push_back(i);
		for(j=i*i, k=i+i; j<=max_n; j+=k) np[j>>1] = 1;
	}
	return r;
}
int main() {
	auto pl = primeList(1e7);
	long long n, m, cnt = 0;
	cin >> n >> m;
	for(auto i : pl) {
		if (i*i >= m) break;
		for(long long j = i * i; j<=m; j *= i) {
			if (j >= n) cnt++;
			if (j > m / i) break;
		}
	}
	cout << cnt;
}