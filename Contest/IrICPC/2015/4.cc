#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> prime = {2};
	bitset<10000> v;
	for(int i =3; i<10000; i+=2) {
		if(v[i]) continue;
		prime.push_back(i);
		for(int j =i*i; j<10000; j+=i) v[j] = 1;
	}

	int n;
	cin >> n;
	int cnt = 0;
	for(int i : prime) {
		if (i < 7) continue;
		if (i > n) break;
		int x = 10101 % i;
		int y = 5;
		while(x) {
			x = x * 100 + 1;
			x = x % i;
			y += 2;
		}
		if (y == i - 2) cnt++;
	}
	cout << cnt;
}