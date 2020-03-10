#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	cout << count_if(s.begin(), s.end(), [](char c) { return c == '1'; });
}