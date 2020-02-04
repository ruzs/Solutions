#include <bits/stdc++.h>

using namespace std;

int pow(long long a, int e, int m) {
	int r = 1;
	while(e) {
		if (e & 1) r = (a * r) % m;
		a = (a * a) % m;
		e >>= 1;
	}
	return r;
}
int main() {
	int n;
	cin >> n;
	cout << pow(2, n, 1e9 + 7);
}