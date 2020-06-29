#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> a(9), b(9);
	for(int & i : a) cin >> i;
	for(int & i : b) cin >> i;
	int sa = 0, sb = 0;
	for(int i =0; i<9; ++i) {
		sa += a[i];
		if (sa > sb) {
			cout << "Yes";
			return 0;
		}
		sb += b[i];
	}
	cout << "No";
}