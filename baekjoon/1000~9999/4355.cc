#include <bits/stdc++.h>

using namespace std;

//Euler phi function, phi(x) = x보다 작은 서로소의 개수
int getEulerPhi(int x) {
	int phi = x;
	for(int i =2; i*i<=x; ++i) {
		if (x % i == 0) phi /= i, phi *= i - 1;
		while(x % i == 0) x /= i;
	}
	if (x > 1) phi /= x, phi *= x - 1;
	return phi;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n) {
		if (!n) break;
		cout << getEulerPhi(n) << '\n';
	}
}