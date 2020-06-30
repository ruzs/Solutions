#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double p;
	int n;
	cin >> p >> n;
	int a[101]{};
	for(int i =0; i<n; ++i) {
		int x;
		char dir;
		cin >> x >> dir;
		if (dir == 'L') {
			for(int i =1; i<x; ++i) a[i]++;
		} else {
			for(int i =x + 1; i<=100; ++i) a[i]++;
		}
	}
	int r = 0, g = 0, b = 0;
	for(int i =1; i<=100; ++i) {
		if (a[i] % 3 == 0) r++;
		else if (a[i] % 3 == 1) g++;
		else b++;
	}
	cout.precision(2);
	cout << fixed << p / 100 * r << '\n' << p / 100 * g << '\n' << p / 100 * b;
}