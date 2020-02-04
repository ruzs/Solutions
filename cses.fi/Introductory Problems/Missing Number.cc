#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, a, s;
	cin >> n;
	s = n * (n + 1) / 2;
	while(--n) {
		cin >> a;
		s -= a;
	}
	cout << s;
}