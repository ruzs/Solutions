#include <bits/stdc++.h>

using namespace std;

int main() {
	int h, m, s, ss;
	cin >> h >> m >> s >> ss;
	s = h * 3600 + m * 60 + s + ss;
	s %= 86400;
	cout << s / 3600 << ' ' << s / 60 % 60 << ' ' << s % 60;
}