#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int main() {
	cin >> n;
	for(int i =1; i * (i - 1) / 2<n; ++i) {
		if ((n - i * (i - 1) / 2) % i == 0) {
			cnt++;
		}
	}
	cout << cnt;
}
