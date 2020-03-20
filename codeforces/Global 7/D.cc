#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		string mat{}, mid{}, rmat{};
		int l, r;
		for(l =0, r =(int)s.size()-1; l + 1<r; ++l, --r) {
			if (s[l] == s[r]) mat += s[l];
			else break;
		}
		auto manacher = [](const string& s) {
			int n = s.size() - 1;
			vector<int> a(n);
			int r = 0, p = 0;
			for (int i=1;i<=n;i++){
				if (i <= r) a[i] = min(a[2*p-i],r-i);
				else a[i] = 0;
				while (i-a[i]-1 > 0 && i+a[i]+1 <= n && s[i-a[i]-1] == s[i+a[i]+1]) a[i]++;
				if (r < i+a[i]) r = i+a[i], p = i;
			}
			return a;
		};
		auto x = s.substr(l, (int)s.size() - l * 2);
		string t = " #";
		for(char c : x) t += c, t += '#';
		auto a = manacher(t);
		int mx = 0, md = -1;
		for(int i =1; i<(int)a.size(); ++i) {
			if ((a[i] + 1 == i || a[i] == (int)a.size() - i) && mx < a[i]) {
				mx = a[i];
				md = i;
			}
		}
		if (~md) mid = t.substr(md - a[md], 2 * a[md] + 1);
		rmat.resize(mat.size());
		reverse_copy(mat.begin(), mat.end(), rmat.begin());
		cout << mat;
		for(char c : mid) if (c != '#') cout << c;
		cout << rmat << '\n';
	}
}