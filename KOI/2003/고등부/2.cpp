#include <bits/stdc++.h>
using namespace std;

int n, d[2][401][401];
vector<int> a ={0}, b ={0};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =0, x; i<n; ++i) {
		cin >> x;
		if (x) a.push_back(x);
	}
	for(int i =0, x; i<n; ++i) {
		cin >> x;
		if (x) b.push_back(x);
	}
	for(int i =1, x =1; i<=n; ++i, x ^=1) {
		for(int j =1; j<a.size(); ++j) {
			for(int k =1; k<b.size(); ++k) {
				int &ref = d[x][j][k];
				ref = d[x^1][j-1][k-1] + a[j] * b[k];
				if (j > 0 && j < i) ref = max(ref, d[x^1][j][k-1]);
				if (k > 0 && k < i) ref = max(ref, d[x^1][j-1][k]);
			}
		}
	}
	cout << d[n&1][a.size()-1][b.size()-1];
}
