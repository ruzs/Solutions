#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	string a, b;
	cin >> a >> b;
	vector<int> v(n);
	for(int i =0; i<n; ++i) v[i] = a[i] != b[i];
}