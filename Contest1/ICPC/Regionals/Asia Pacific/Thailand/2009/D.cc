#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

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

bool ns[N];

bool isSanguensu(int x) {
	if (ns[x]) return 0;
	if (x == 1) return 1;
	int nxt = 0, t = x;
	while(t) nxt += (t % 10) * (t % 10), t /= 10;
	ns[x] = 1;
	if (isSanguensu(nxt)) {
		ns[x] = 0;
		return 1;
	}
	return 0;
}
int main() {
	int n;
	cin >> n;
	auto pl = primeList(n);
	for(auto i : pl) if (isSanguensu(i)) cout << i << '\n';
}