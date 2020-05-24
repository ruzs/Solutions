#include <bits/stdc++.h>

using namespace std;

struct pt {
	long long x, y;
	bool operator < (pt & b) const {
		return x < b.x || x == b.x && y < b.y;
	}
};
istream& operator >> (istream& in, pt & p) {
	cin >> p.x >> p.y;
	return in;
}

long long prod(const pt & a, const pt & b, const pt & c) {
	return (a.x - b.x) * (b.y - c.y) + (b.x - c.x) * (b.y - a.y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	pt a, b;
	cin >> a >> b;

	vector<pt> p = {a, b};
	while(n--) {
		int y, l, r;
		cin >> y >> l >> r;
		if (prod(a, b, {l, y}) > 0) p.push_back({l, y});
		else if (prod(a, b, {r, y}) < 0) p.push_back({r, y});
	}

	sort(p.begin(), p.end());
	stable_sort(p.begin() + 1, p.end(), [&](const pt&a, const pt&b) {
		return prod(p[0], a, b) > 0;
	});
	vector<pt> ch;
	for(auto & i : p) {
		while(ch.size() > 1 && prod(ch[(int)ch.size() - 2], ch.back(), i) <= 0)
			ch.pop_back();
		ch.push_back(i);
	}
	
	n = ch.size();
	long long ans = 0, area = 0;
	for(int i =0, j, k; i<n; ++i) {
		j = (i + 1) % n;
		k = (j + 1) % n;
		while(k != i) {
			ans = max(ans, area = abs(prod(ch[i], ch[j], ch[k])));
			if (abs(prod(ch[i], ch[j], ch[(k + 1) % n])) < area) {
				j = (j + 1) % n;
			} else {
				k = (k + 1) % n;
			}
		}
	}
	if (ans & 1) cout << ans / 2 << ".5";
	else cout << ans / 2;
}