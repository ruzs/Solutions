#include <bits/stdc++.h>

using namespace std;

int n;

bool isPrime(int x) {
	if (x != 2 && x % 2 == 0 || x < 2) return 0;
	for(int i =3; i * i <= x; i += 2) if (x % i == 0) return 0;
	return 1;
}
void rec(int x, int n) {
	if (!n) {
		cout << x << '\n';
		return;
	}
	if (isPrime(x * 10 + 1)) rec(x * 10 + 1, n - 1);
	if (isPrime(x * 10 + 3)) rec(x * 10 + 3, n - 1);
	if (isPrime(x * 10 + 7)) rec(x * 10 + 7, n - 1);
	if (isPrime(x * 10 + 9)) rec(x * 10 + 9, n - 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rec(2, n - 1);
	rec(3, n - 1);
	rec(5, n - 1);
	rec(7, n - 1);
}
