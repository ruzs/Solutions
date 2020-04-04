#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	const int N = 1e7;
	bitset<N> v;
	for(int i =3; i*i<=N; ++i) {
		if (v[i]) continue;
		for(int j = i*i; j<=N; j+=i) v[j] = 1;
	}
	vector<int> prime={2};
	for(int i =3; i<=N; i+=2) if (!v[i]) prime.push_back(i);
	cout << prime[n - 1];
}