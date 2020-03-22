#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a[9], sum = 0;
	for(int i =0; i<9; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + 9);
	sum -= 100;
	int exc;
	for(int i =0; i<8; ++i) {
		if (binary_search(a + i + 1, a + 9, sum - a[i])) {
			exc = a[i];
		}
	}
	for(int i =0; i<9; ++i) {
		if (a[i] == exc || a[i] == sum - exc) continue;
		cout << a[i] << '\n';
	}
}