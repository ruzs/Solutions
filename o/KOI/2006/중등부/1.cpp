#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;

int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	if (n == 1) cout << "1 1";
	else if (n <= 3) cout << "2 2";
	else {
		cout << n / 3 + (n % 3 ? 1 : 0) << ' ';
		int c = 0;
		while(n % 4 == 0) n >>= 2, c++;
		if (n % 2 == 0) n >>= 1, c++;
		for(int i =3; i<=n; i += 2) while(n % i == 0) n /= i, c++;
		cout << c;
	}
}
