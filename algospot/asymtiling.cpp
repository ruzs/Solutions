#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7;
int s[101] = {1,1,2,1,}, a[101] = {0,0,0,2,};
int main() {
	for(int i =4; i<=100; ++i) s[i] = (s[i - 2] + s[i - 4]) % m;
	for(int i =4; i<=100; ++i)
	a[i] = (0LL + s[i - 3] + s[i - 3] + a[i - 3] + a[i - 3] + a[i - 2] + a[i - 4]) % m;
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		cout << a[n] << '\n';
	}
}
