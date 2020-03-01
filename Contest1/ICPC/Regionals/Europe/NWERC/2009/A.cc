#include <bits/stdc++.h>

using namespace std;

const int N = 1e7+5;

bool np[N>>1] = {1,};

inline auto primeList(int max_n) {
	long long i =1, j, k;
	while((i+=2) <= max_n) {
		if (np[i>>1]) continue;
		for(j=i*i, k=i+i; j<=max_n; j+=k) np[j>>1] = 1;
	}
}
inline bool isPrime(int x) {
	if (x % 2 == 0) return x == 2;
	return !np[x>>1];
}

void solve() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	set<int> st;
	int cnt = 0, all = 1<<(int)s.size();
	for(int msk =1; msk<all; ++msk) {
		vector<int> a;
		for(int i =0; i<s.size(); ++i) {
			if (msk & (1 << i)) a.push_back(s[i] & 15);
		}
		do {
			int t = 0;
			for(int i : a) t = t * 10 + i;
			if (isPrime(t) && !st.count(t)) cnt++;
			st.insert(t);
		} while(next_permutation(a.begin(), a.end()));
	}
	cout << cnt << '\n';
}
int main() {
	primeList(1e7);
	int T; cin >> T;
	while(T--) solve();
}