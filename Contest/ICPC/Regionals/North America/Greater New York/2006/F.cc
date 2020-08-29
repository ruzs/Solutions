#include <bits/stdc++.h>

using namespace std;

vector<int> phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    iota(phi.begin(), phi.end(), 0); //[0,1,2,3,4,5,...,n]

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	auto phi = phi_1_to_n(1000);
	phi[0] = 1;
	for(int i =1; i<=1000; ++i)
		phi[i] = phi[i - 1] + phi[i] * 2;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << phi[n] << '\n';
	}
}