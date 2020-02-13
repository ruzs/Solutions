#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c >= 100) cout << "OK";
	else {
		int mn = min({a,b,c});
		if (mn == a) cout << "Soongsil";
		else if (mn == b) cout << "Korea";
		else cout << "Hanyang";
	}
}