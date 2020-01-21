#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define BASE 1000000000
#define DIGIT 9
class bint {
	bool neg = 0;
	vi a;
public:
	bint() {}
	bint(bool _neg, const vi& x) : neg(_neg), a(x) {}

	void assign(const string& s) {
		neg = s.front() == '-';
		for(int i =(int)s.size() - DIGIT; i>=neg; i-=DIGIT) {
			a.push_back(stoi(s.substr(i, DIGIT)));
		}
		if (((int)s.size() - 1) % DIGIT + 1 > neg)
			a.push_back(stoi(s.substr(neg, ((int)s.size() - 1) % DIGIT + 1 - neg)));
	}
	void print() const {
		if (neg && a.back() != 0) cout << '-';
		cout << a.back();
		for(int i =(int)a.size() - 2; i>=0; --i) {
			cout.width(DIGIT);
			cout.fill('0');
			cout << a[i];
		}
	}
	const bint operator-() const {
		return bint(!neg, a);
	}
	const bint operator+(const bint& B) const {
		if (neg == B.neg) {
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
			return bint(neg, r);
		}
		return neg ? B - -*this : *this - -B;
	}
	const bint operator-(const bint& B) const {
		if (neg == B.neg) {
			auto& b = B.a;
			if (a.size() < b.size()) return -(B - *this);
			if (a.size() == b.size()) {
				for(int i =(int)a.size() - 1; i>=0; --i)
					if (a[i] < b[i]) return -(B - *this);
					else if (a[i] > b[i]) break;
			}
			vi r(a);
			for(int i =0; i<(int)b.size(); ++i) {
				if (r[i] < b[i]) {
					r[i] += BASE;
					r[i + 1]--;
				}
				r[i] -= b[i];
			}
			while(r.size() > 1 && r.back() == 0) r.pop_back();
			return bint(neg, r);
		}
		return *this + -B;
	}
	const bint operator*(const bint& B) const {
		auto&b = B.a;
		vi r(a.size() + b.size() + 1, 0);
		for(int i =0; i<(int)a.size(); ++i) {
			for(int j =0; j<(int)b.size(); ++j) {
				long long tmp = 1LL * a[i] * b[j] + r[i + j];
				r[i + j + 1] += tmp / BASE;
				r[i + j] = tmp % BASE;
			}
		}
		while(r.size() > 1 && r.back() == 0) r.pop_back();
		return bint(neg != B.neg, r);
	}
};
istream& operator>>(istream& cin, bint& a) {
	string s; cin >> s;
	a.assign(s);
	return cin;
}
ostream& operator<<(ostream& cout, const bint& a) {
	a.print();
	return cout;
}

int main() {
	bint a, b;
	cin >> a >> b;
	cout << a + b << '\n' << a - b << '\n' << a * b;
}