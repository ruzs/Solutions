#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
string s;
int decision(int l, int r, int x) {
	if (l > r) return 0;
	if (s[l] == s[r]) return decision(l + 1, r - 1, x);
	else if (x && !decision(l, r - 1, 0) || !decision(l + 1, r, 0)) return 1;
	return 2;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while(n--){
		cin >> s;
		int ans = decision(0, s.size() - 1, 1);
		cout << (ans < 2 ? ans : 2) << '\n';
	}
}
