#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a[8] = {2,1,2,3,4,5,4,3};
	cin >> n;
	cout << a[n % 8];
}