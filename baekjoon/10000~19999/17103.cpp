#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> p;
bool np[1000000];
inline void sieve() {
	int i, j;
	p.push_back(2);
	for(i =3; i<1000000; i+=2) {
		if (np[i]) continue;
		p.push_back(i);
		for(j =i+i; j<1000000; j+=i)
			np[j] = 1;
	}
}
int main() {
	sieve();
	cin >> t;
	while(t--) {
		cin >> n;
		int cnt = 0;
		for(int i : p) {
			if (i > n / 2) break;
			cnt += binary_search(p.begin(), p.end(), n - i);
		}
		cout << cnt << '\n';
	}
}
