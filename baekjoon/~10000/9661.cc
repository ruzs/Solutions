#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;
	array<int, 6> a = {0, 1, 0, 1, 1};
	cout << (a[n % 5] ? "SK" : "CY");
}