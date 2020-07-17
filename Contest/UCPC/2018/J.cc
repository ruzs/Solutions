#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> a = { "baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby", "sukhwan"};
    int n;
    cin >> n;
    int r = (n - 1) / 14, m = (n - 1) % 14;
	if (r > 2 && m % 4 == 2) cout << "tu+ru*" << 2 + r;
	else if (r > 3 && m % 4 == 3) cout << "tu+ru*" << 1 + r;
	else if (m % 4 == 2 || m % 4 == 3) {
		cout << a[m];
		for (int i = 0; i < r; ++i) cout << "ru";
	}
	else cout << a[m];
}