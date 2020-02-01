#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	pair<int, int> p = {1, 0}, np = {0, 1};
	cin >> n;
	while(n--) {
		auto t = np;
		np.first += p.first;
		np.second += p.second;
		p = t;
	}
	cout << p.first << ' ' << p.second;
}