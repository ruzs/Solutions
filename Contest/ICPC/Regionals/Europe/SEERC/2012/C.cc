#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int MAX = 1e7;
	bitset<MAX> v;
	for(int i =3; i*i<MAX; i+=2) {
		if(v[i]) continue;
		for(int j =i*i; j<MAX; j+=i) v[j] = 1;
	}
	vector<int> prime = {2};
	for(int i =3; i<MAX; i+=2)
		if(!v[i]) prime.push_back(i);

	int n, m;
	while(cin >> n >> m) {
		cout << upper_bound(prime.begin(), prime.end(), m) - 
				lower_bound(prime.begin(), prime.end(), n) << "\n\n";
	}
}