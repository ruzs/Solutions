#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> a;
	for(int i =1; i<=100; ++i) a.push_back(i * i * i);
	for(int i =4; i<(int)a.size(); ++i) {
		for(int j =1; j<i; ++j) {
			for(int k =j + 1; k<i; ++k) {
				for(int l =k + 1; l<i; ++l) {
					if (a[i] == a[j] + a[k] + a[l]) {
						cout << "Cube = " << i + 1 << ", Triple = ("
						<< j + 1 << ',' << k + 1 << ',' << l + 1 << ")\n";
					}
				}
			}
		}
	}
}