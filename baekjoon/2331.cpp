#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n, p, x;
set<int> ans;
int f(int x) {
	int r =0;
	while(x) {
		r += pow(x % 10, p);
		x /= 10;
	}
	return r;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p;
	ans.insert(n);
	x = n;
	while(ans.find(x = f(x)) == ans.end()) {
		ans.insert(x);
	}
	while(ans.find(x = f(x)) != ans.end()) {
		ans.erase(x);
	}
	cout << ans.size();
}
