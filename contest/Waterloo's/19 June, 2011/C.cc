#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define BASE 1000000000
#define DIGIT 9
class bint {
	vi a;
public:
	bint() {}
	bint(int x) {
		if (x >= BASE) a = {x/BASE, x%BASE};
		else a = {x};
	}
	bint(const vi& v) : a(v) {}

	bint& operator=(const bint& B) {
		a = B.a;
		return *this;
	}
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

	const int operator[](const int idx) const { return a[idx]; }
	const int back() const { return a.back(); }
	const size_t size() const { return a.size(); }
};
ostream& operator<<(ostream& cout, const bint& a) {
	cout << a.back();
	for(int i =(int)a.size() - 2; i>=0; --i) {
		cout.width(DIGIT);
		cout.fill('0');
		cout << a[i];
	}
	return cout;
}
int main() {
	int n;
	cin >> n;
	bint p(0), np(1), t;
	while(--n) {
		t = np;
		np = np + p;
		p = t;
	}
	cout << np;
}