#include <bits/stdc++.h>

using namespace std;

using bint = vector<char>;

bint operator * (bint & a, bint & b) {
	bint r(a.size() + b.size() + 1, 0);
	for(int i =0; i<a.size(); ++i)
		for(int j =0; j<b.size(); ++j) {
			int t = a[i] * b[j] + r[i + j];
			r[i + j + 1] += t / 10;
			r[i + j] = t % 10;
		}
	while(r.size() > 1 && r.back() == 0) r.pop_back();
	return r;
}
bint d[370] = {{1},};

int main() {
	int n;
	for(int i =1; i<367; ++i) {
		int t =i;
		bint s;
		while(t) s.push_back(t%10), t/=10;
		d[i] = d[i - 1] * s;
	}
	while(cin >> n) {
		if (!n) break;
		int ab[26]{};
		for(char c : d[n]) ab[c]++;
		cout << n << "! --\n";
		for(int i =0; i<5; ++i) {
			cout << "   (" << i << ')';
			cout.width(5);
			cout << ab[i] << ' ';
		} cout << '\n';
		for(int i =5; i<10; ++i) {
			cout << "   (" << i << ')';
			cout.width(5);
			cout << ab[i] << ' ';
		} cout << '\n';
	}
}