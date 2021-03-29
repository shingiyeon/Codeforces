//# Author : godgiyeon =========================#
//# Problem Title : Binary Removals ========#
//# Time Stamp : 2021-03-21T15:16:00 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string.h>
using namespace std;
int main() {
	cin.tie(NULL); ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		string str; cin >> str;
		bool of = false;
		bool ans = true;
		for(int i=1; i<str.size(); i++) {
			if(str[i] == '1' && str[i-1] == '1') of = true;
			if(of) {
				if(str[i] == '0' && str[i-1] == '0') {
					ans = false;
				}
			}
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
		  
	}
}