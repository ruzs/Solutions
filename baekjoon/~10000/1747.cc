#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	struct prime {
		vector<int> p;
		bitset<1000005> np;
		prime(int max_n) : p({2}) {
			int i, j, k;
			for (i = 3; i * i <= max_n; i += 2) {
				if (np[i >> 1]) continue;
				p.push_back(i);
				for (j = i * i, k = i + i; j <= max_n; j += k)
					np[j >> 1] = 1;
			}
			while (i <= max_n) {
				if (!np[i >> 1]) p.push_back(i);
				i += 2;
			}
		}
		auto begin() { return p.begin(); }
		auto end() { return p.end(); }
	} p(2000000);
	int n;
	cin >> n;
	auto lb = lower_bound(p.begin(), p.end(), n);
	auto isPalindrome = [](int a) {
		string t = to_string(a);
		for(int i =0; i<(int)t.size() / 2; ++i) {
			if (t[i] != t[(int)t.size() - i - 1]) return false;
		}
		return true;
	};
	while(lb != p.end()) {
		if (isPalindrome(*lb)) {
			cout << *lb;
			return 0;
		}
		lb++;
	}
}