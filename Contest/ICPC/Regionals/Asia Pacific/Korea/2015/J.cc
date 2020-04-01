#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	bitset<1000> v;
	for(int i=3; i<1000; i+=2) {
		if (v[i]) continue;
		for(int j =i*i; j<1000; j+=i) v[j] = 1;
	}
	set<int> p = {2};
	for(int i =3; i<1000; i+=2) if (!v[i]) p.insert(i);

	int n;
	cin >> n;
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		[&] {
			for(int i : p) {
				for(int j : p) {
					if (p.count(x - i - j)) {
						multiset<int> ans = {j, i, x - i - j};
						for(int k : ans) cout << k << ' ';
						cout << '\n';
						return;
					}
				}
			}
			cout << "0\n";
		} ();
	}
}