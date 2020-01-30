#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

bool np[N>>1];

vector<long long> prime = {2};
inline void primeList(int max_n) {
	long long i =1, j, k;
	while((i+=2) <= max_n) {
		if (np[i>>1]) continue;
		prime.push_back(i);
		for(j=i*i, k=i+i; j<=max_n; j+=k) np[j>>1] = 1;
	}
}
void solve() {
	long long n;
	cin >> n;
	for(auto i : prime) if (n % i == 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main() {
	primeList(1e6);
	int T; cin >> T;
	while(T--) solve();
}