#include <bits/stdc++.h>
using namespace std;

int soinsu(int x) {
	int cnt =0;
	for(int i =2; i*i<=x; ++i) {
		while(x % i == 0) cnt++, x /= i;
	}
	return cnt + (x > 1);
}
bool isPrime(int x) {
	if (x == 1) return 0;
	if (x % 2 == 0) return x == 2;
	for(int i =3; i*i<=x; i += 2) {
		if (x % i == 0) return 0;
	}
	return 1;
}
int main() {
	int s, e; cin >> s >> e;
	int cnt =0;
	for(int i =s; i <= e; ++i) {
		if (isPrime(soinsu(i))) cnt++;
	}
	cout << cnt;
}
