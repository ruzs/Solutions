#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	if (n == 1) {
		cout << "no";
		return 0;
	}
	int f = 0;
	for(int i =2; i*i<=n; ++i) {
		if (n % i == 0) {
			if (f) {
				cout << "no";
				return 0;
			}
			while(n % i == 0) n /= i;
			f = 1;
		}
	}
	if (n > 1 && f) cout << "no";
	else cout << "yes";
}