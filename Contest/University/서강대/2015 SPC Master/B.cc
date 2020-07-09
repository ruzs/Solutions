#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	int a1 = count(a.begin(), a.end(), '1');
	int b1 = count(b.begin(), b.end(), '1');
	if (a1 >= b1 || a1 % 2 && a1 + 1 == b1) cout << "VICTORY";
	else cout << "DEFEAT";
}