#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		string s;
		cin>>s;
		int ab[26]{},f=0;
		for(int i=0;i<s.size();++i){
			ab[s[i]-'A']++;
			if(ab[s[i]-'A']%3==0){
				if(s[i]!=s[i+1]){
					f=1;
					break;
				}
				i++;
			}
		}
		cout<<(f?"FAKE\n":"OK\n");
	}
}