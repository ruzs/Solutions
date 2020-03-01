#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int d[50001];
int dp(int n) {
	if (n < 0) return 1e9;
	if (n == 0) return 0;
	int& ref = d[n];
	if (ref != -1) return ref;
	ref = 1e9;
	for(int i : a) {
		ref = min(ref, dp(n - i) + 1);
	}
	return ref;
}
int main() {
	int n;
	cin >> n;
	for(int i =1; i*i<50000; ++i) a.push_back(i*i);
	memset(d, -1, sizeof d);
	cout << dp(n);
}