#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m), c;
	for(int & i : a) cin >> i;
	for(int & i : b) cin >> i;
	merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
	for(int i : c) cout << i << ' ';
}