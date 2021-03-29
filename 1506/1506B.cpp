//# Author : godgiyeon =========================#
//# Problem Title : Partial Replacement ====#
//# Time Stamp : 2021-03-26T00:58:57 ===========#
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
		int n, k; string str;
		cin >> n >> k;
		cin >> str;
		int cnt = 0;
		for(int i=0; i<n; i++) {
			if(str[i] == '*') {
				str[i] = 'x';
				cnt++;
				break;
			}
		}
		for(int i=n-1; i>=0; i--) {
			if(str[i] == '*') {
				str[i] = 'x';
				cnt++;
				break;
			}
		}
		for(int i=0; i<n; i++) {
			if(str[i] == 'x') {
				bool flag = false;
				int max_val = -1;
				for(int j=i+1; j<=i+k && j<n; j++) {
					if(str[j] == 'x') flag = true;
					if(str[j] == '*') max_val = max(max_val, j);
				}
				if(!flag) {
					if(max_val != -1) {
						str[max_val] = 'x';
						cnt++;
					}
				}
			}
		}
		//cout << str << "\n";
		cout << cnt << "\n";
		
	}
}