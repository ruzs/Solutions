#include <bits/stdc++.h>
using namespace std;

int n, a[20];
bitset<2000001> v;
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	for(int s =1; s<1<<n; ++s) {
		int sum =0;
		for(int i =0; i<n; ++i) {
			if (s & (1 << i)) sum += a[i];
		}
		v[sum] = 1;
	}
	for(int i =1; i<=2000000; ++i) {
		if (!v[i]) return cout << i, 0;
	}
}
