#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	long long s = 1LL * n * (n + 1) / 2;
	if (s % 2) cout << "NO";
	else {
		cout << "YES\n";
		s /= 2;
		vector<int> a, b;
		for(int i =n; i; --i) {
			if (s >= i) a.push_back(i), s -= i;
			else b.push_back(i);
		}
		cout << a.size() << "\n";
		for(int i : a) cout << i << ' ';
		cout << "\n" << b.size() << "\n";
		for(int i : b) cout << i << ' ';
	}
}