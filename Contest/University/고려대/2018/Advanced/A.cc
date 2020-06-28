#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> a = {0, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};
	int n;
	cin >> n;
	cout << upper_bound(a.begin(), a.end(), n) - a.begin();
}