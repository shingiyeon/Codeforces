//# Author : godgiyeon =========================#
//# Problem Title : Epic Transformation ====#
//# Time Stamp : 2021-03-26T00:26:39 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <math.h>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n;
		map<int, int> m; cin >> n;
		for(int i=0; i<n; i++) {
			int tmp; cin >> tmp;
			m[tmp]++;
		}
		int max_val = 0;
		for(auto it=m.begin(); it!=m.end(); it++) {
			max_val = max(max_val, it->second);
		}
		if(max_val > n - max_val) {
			cout << max_val - n + max_val << "\n";
		}
		else {
			cout << n % 2 << "\n";
		}
	}
}