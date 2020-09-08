#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	cout << (long long)(n / k + (n % k ? 1 : 0)) * (m / k + (m % k ? 1 : 0));
}