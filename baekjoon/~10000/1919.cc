#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	vector<int> ab(26);
	for(char c : a) ab[c - 'a']++;
	for(char c : b) ab[c - 'a']--;
	int ans = 0;
	for(int i : ab) ans += abs(i);
	cout << ans;
}