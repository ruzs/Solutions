#include <bits/stdc++.h>

using namespace std;

int main() {
	int h, m;
	cin >> h >> m;
	if (h % 30 * 12 == m) cout << "O";
	else cout << "X";
}