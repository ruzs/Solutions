#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, p, np;
	long long cnt =0;

	cin >> n >> p;
	while(--n) {
		cin >> np;
		if (np < p) cnt += p - np;
		p = max(p, np);
	}
	cout << cnt;
}