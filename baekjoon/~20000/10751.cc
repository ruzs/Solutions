#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s;
	cin >> n >> s;
	long long ans = 0, C = 0, O = 0;
	for(char c : s) {
		if (c == 'C') C++;
		else if (c == 'O') O += C;
		else ans += O;
	}
	cout << ans;
}