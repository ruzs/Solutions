#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string input, a{}, b{};
		while(cin >> input) {
			if (input == "end") break;
			if (input == "nil") a += 'n';
			else a += input;
		}
		while(cin >> input) {
			if (input == "end") break;
			if (input == "nil") b += 'n';
			else b += input;
		}
		bool ok = (a.back() == b.back());
		vector<char> ap(26, 0), bp(26, 0);
		stack<char> rt;
		while(a.size()) {
			if (rt.size()) {
				if (a.back() != 'n') ap[a.back() - 'A'] = rt.top();
				rt.pop();
			}
			if (a.back() != 'n') {
				rt.push(a.back());
				rt.push(a.back());
			}
			a.pop_back();
		}
		while(b.size()) {
			if (rt.size()) {
				if (b.back() != 'n') bp[b.back() - 'A'] = rt.top();
				rt.pop();
			}
			if (b.back() != 'n') {
				rt.push(b.back());
				rt.push(b.back());
			}
			b.pop_back();
		}
		if (ok && ap == bp) cout << "true\n";
		else cout << "false\n";
	}
}