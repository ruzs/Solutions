#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int N = 2e5 + 5;

int t;
string a, b;

vi getInt(const string & s) {
	vi r;
	for(char c : s) r.push_back(c == 'M');
	return r;
}
vi mul(const vi & a, const vi & b) {
	vi r(a.size() + b.size() - 1, 0);
	for(int i =0; i<a.size(); ++i) {
		for(int j =0; j<b.size(); ++j) {
			r[i + j] += a[i] * b[j];
		}
	}
	return r;
}
vi add(const vi & a, const vi & b) {
	if (a.size() > b.size()) return add(b, a);
	vi r = b;
	for(int i =0; i<a.size(); ++i) r[i] += a[i];
	return r;
}
vi sub(const vi & a, const vi & b) {
	vi r = b;
	for(int i =0; i<a.size(); ++i) r[i] -= a[i];
	return r;
}
vi pbz(const vi & a, int l) {
	vi r(a.size() + l);
	for(int i =0; i<a.size(); ++i) r[i + l] = a[i];
	return r;
}
vi karatsuba(const vi & a, const vi & b) {
	if (a.size() > b.size()) return karatsuba(b, a);
	if (b.size() < 50) return mul(a, b);
	auto L = b.size() / 2;
	vi a0(a.begin(), a.begin() + min(a.size(), L));
	vi a1(a.begin() + min(a.size(), L), a.end());
	vi b0(b.begin(), b.begin() + L);
	vi b1(b.begin() + L, b.end());

	vi a1b1 = karatsuba(a1, b1);
	vi a0b0 = karatsuba(a0, b0);
	vi a0a1b0b1 = sub(a0b0, sub(a1b1, karatsuba(add(a1, a0), add(b1, b0))));

	a1b1 = pbz(a1b1, L * 2);
	a0a1b0b1 = pbz(a0a1b0b1, L);
	return add(add(a1b1, a0b0), a0a1b0b1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--){
		cin >> a >> b;
		reverse(a.begin(), a.end());
		auto r = karatsuba(getInt(a), getInt(b));
		int cnt = 0;
		for(int i =a.size() -1; i<b.size(); ++i) {
			if (r[i]) cnt++;
		}
		cout << b.size() - a.size() + 1 - cnt << '\n';
	}
}
