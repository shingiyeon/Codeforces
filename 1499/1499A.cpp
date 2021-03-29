//# Author : godgiyeon =========================#
//# Problem Title : Domino on Windowsill ===#
//# Time Stamp : 2021-03-21T14:57:03 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n, k1, k2, w, b; cin >> n >> k1 >> k2 >> w >> b;
		int W = k1 + k2;
		int B = n - k1 + n - k2;
		bool flag = true;
		if(W/2 < w || B/2 < b) flag = false;
		if(flag) cout << "YES\n";
		else cout << "NO\n";

	}
}