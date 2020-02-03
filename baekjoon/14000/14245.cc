#include <bits/stdc++.h>

using namespace std;

#define N 1<<19
struct fwt {
	int a[N];
	void add(int p, int x) {
		while(p < N) a[p] ^= x, p += p & -p;
	}
	auto sum(int p) {
		int r = a[p];
		while(p -= p & -p) r ^= a[p];
		return r;
	}
} fw;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b, c, o;
	cin >> n;
	for(int i =1; i<=n; ++i) {
		cin >> a;
		fw.add(i, a);
		fw.add(i + 1, a);
	}
	cin >> n;
	while(n--) {
		cin >> o;
		if (o == 1) {
			cin >> a >> b >> c;
			fw.add(a + 1, c);
			fw.add(b + 2, c);
		}
		else {
			cin >> a;
			cout << fw.sum(a + 1) << '\n';
		}
	}
}