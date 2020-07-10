#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a[6]{};
	for(int i =0; i<n; ++i) {
		int x, y;
		cin >> x >> y;
		a[x]++;
		a[y]++;
	}
	if (a[1] == 2 && a[3] == 2 && a[4] == 2 && a[2] == 0 && a[5] == 0) cout << "Wa-pa-pa-pa-pa-pa-pow!";
	else cout << "Woof-meow-tweet-squeek";
}