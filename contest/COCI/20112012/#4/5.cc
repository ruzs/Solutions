#include <bits/stdc++.h>

using namespace std;

bool np[32000];
vector<long long> prime = {2};
void primeList(int max_n) {
	long long i =1, j, k;
	while((i+=2) <= max_n) {
		if (np[i>>1]) continue;
		prime.push_back(i);
		for(j=i*i, k=i+i; j<=max_n; j+=k) np[j>>1] = 1;
	}
}
const int N = 2e7;
bool b[N];
inline void ex_sieve(int p) {
	int end = 1e9 / p;
	for(int i : prime) {
		if (i >= p) break;
		for(int j =i; j<=end; j+=i) {
			b[j] = 1;
		}
	}
}

bool valid(long long x, int n, int idx) {
	long long s = x;
	for(int msk = 1; msk<1<<idx; ++msk) {
		long long t = 1;
		for(int j =0; j<idx; ++j) {
			if (msk & (1 << j)) t *= prime[j];
		}
		if (__builtin_popcount(msk) & 1) s -= x / t;
		else s += x / t;
	}
	return s < n;
}
int main() {
	primeList(32000);
	int n, p;
	cin >> n >> p;
	if (n == 1) cout << p;
	else if (1LL * p * p > 1e9) cout << 0;
	else if (p > 50) {
		ex_sieve(p);
		int i, end = 1e9 / p;
		n--;
		for(i =p; i<=end; ++i) {
			if (b[i]) continue;
			if (!--n) break;
		}
		if (n || i * p > 1e9) cout << 0;
		else cout << i * p;
	}
	else {
		int idx = lower_bound(prime.begin(), prime.end(), p) - prime.begin();
		long long nth = 0, j = 1000000000;
		while(j /= 2) {
			while(valid(nth + j, n, idx)) nth += j;
		}
		cout << (++nth * p > 1e9 ? 0 : nth * p);
	}
}