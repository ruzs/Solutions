#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	int t = 135519;
	cin >> s;
	for(char c : s) if (~t & (1 << (c - 65))) cout << c;
}
