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
	const int operator[](const int idx) const { return a[idx]; }
	const int back() const { return a.back(); }
	const size_t size() const { return a.size(); }
};
istream& operator>>(istream& cin, bint& a) {
	string s; cin >> s;
	a = s;
	return cin;
}
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
	bint a(1), b(3);
	vector<bint> v, ans;
	for(int i =0; i<64; ++i) {
		v.push_back(a);
		a = a * b;
	}
	unsigned long long k;
	while(cin >> k) {
		if (!k) break;
		ans.clear();
		for(int i =63; i>=0; --i) {
			if (k > (1LL << i)) {
				k -= 1LL << i;
				ans.push_back(v[i]);
			}
		}
		sort(ans.begin(), ans.end());
		cout << "{ ";
		if (ans.size()) {
			for(int i =0; i<(int)ans.size() - 1; ++i)
				cout << ans[i] << ", ";
			cout << ans.back() << ' ';
		}
		cout << "}\n";
	}
}