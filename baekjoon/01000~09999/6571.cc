#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define BASE 1000000000
#define DIGIT 9
class bint {
	vi a;
public:
	bint() {}
	bint(const string &s) {
		int i = (int)s.size() % DIGIT;
		if (i) a.push_back(stoi(s.substr(0, i)));
		while(i + DIGIT <= (int)s.size())
			a.push_back(stoi(s.substr(i, DIGIT))), i += DIGIT;
		reverse(a.begin(), a.end());
	}
	bint(int x) {
		if (x >= BASE) a = {x/BASE, x%BASE};
		else a = {x};
	}
	bint(const vi& v) : a(v) {}

	const bint operator+(const bint& B) const {
		auto& b = B.a;
		int n = max(a.size(), b.size());
		vi r(n + 1, 0);
		for(int i =0; i<n; ++i) {
			if (i < b.size()) r[i] += b[i];
			if (i < a.size()) r[i] += a[i];
			if (r[i] >= BASE) {
				r[i] -= BASE;
				r[i + 1]++;
			}
		}
		while(r.size() > 1 && r.back() == 0) r.pop_back();
		return bint(r);
	}

	const bool operator<(const bint& B) const {
		auto& b = B.a;
		if (a.size() != b.size()) return a.size() < b.size();
		for(int i =(int)a.size() - 1; i>=0; --i) {
			if (a[i] != b[i]) return a[i] < b[i];
		}
		return 0;
	}
	const bool operator==(const bint& B) const {
		return a == B.a;
	}
};
istream& operator>>(istream& cin, bint& a) {
	string s; cin >> s;
	a = s;
	return cin;
}
int main() {
	bint a, b, p(1), np(2), t, mx("1" + string(101, '0'));
	vector<bint> fibo = { p, np };
	while(np < mx) {
		t = np;
		np = np + p;
		p = t;
		fibo.push_back(np);
	}
	while(cin >> a >> b) {
		if (a == bint(0) && b == bint(0)) break;
		cout << upper_bound(fibo.begin(), fibo.end(), b)
		- lower_bound(fibo.begin(), fibo.end(), a) << '\n';
	}
}