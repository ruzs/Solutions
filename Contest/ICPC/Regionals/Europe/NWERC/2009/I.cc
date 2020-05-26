#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	struct pt {
		int x, y, i;
		bool operator < (pt & b) const {
			return x < b.x || x == b.x && y < b.y;
		}
	};
	auto ccw = [](pt a, pt b, pt c) {
		return (a.x - b.x) * (b.y - c.y) + (b.x - c.x) * (b.y - a.y);
	};

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<pt> p(n);
		for(int i =0; i<n; ++i) {
			cin >> p[i].x >> p[i].y;
			p[i].i = i;
		}

		sort(p.begin(), p.end());
		stable_sort(p.begin() + 1, p.end(), [&](pt a, pt b) {
			return ccw(p[0], a, b) > 0;
		});

		for(int i =n - 1; i>0; --i) {
			if (ccw(p[0], p[n - 1], p[i]) != 0) {
				reverse(p.begin() + i + 1, p.end());
				break;
			}
		}

		for(pt & i : p) cout << i.i << ' ';
		cout << '\n';
	}
}